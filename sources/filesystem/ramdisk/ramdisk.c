///////////////////////////////////////////////////////////////////////////////
//	
//						Copyright 2013 xxxxxxx, xxxxxxx
//	File:	ramdisk.c
//	Author:	Bala B. (bhat.balasubramanya@gmail.com)
//	Description: Utility functions
//	
///////////////////////////////////////////////////////////////////////////////

#include "ramdisk.h"
#include "os_core.h"
#include "util.h"
#include "os_process.h"

OS_Return ramdisk_init(void * addr);

static INT32 getToken(INT8 * dst, const INT8 * path);

#ifdef _USE_STD_LIBS
	#define FAULT(x, ...) printf(x, ...);
#else
	#define FAULT(x, ...)
#endif

static FS_RamdiskHdr * ramdisk = NULL;
static FS_FileHdr * root = NULL;

// Static functions
static BOOL ramdisk_assert_open(INT32 fd);
static BOOL ramdisk_assert_ownership(INT32 fd);
static INT32 getToken(INT8 * dst, const INT8 * path);

OS_Return ramdisk_init(void * addr)
{
	if(!addr) {
		FAULT("ramdisk_init failed: address argument is NULL\n");
		return BAD_ARGUMENT;
	}
		
	ramdisk = (FS_RamdiskHdr *)addr;
	
	// Validate the ramdisk file
	if(strcmp(ramdisk->ident, RAMDISK_IDENT_STRING) != 0) {
		FAULT("The ramdisk image is invalid\n");
		return RAMDISK_INVALID;
	}
	
	// Validate crc
	// TODO: Right now I am just using file size as the CRC
	if(ramdisk->crc != ramdisk->size) 
	{
		FAULT("The CRC of the ramdisk image is not valid\n");
		return RAMDISK_INVALID;
	}

	// Get a pointer to root folder
	root = (FS_FileHdr *)((INT8 *)addr + ramdisk->rootOffset);
	
	// Verify that the root is a folder
	if((root->flags & F_DIR_MASK) != F_DIR) 
	{
		FAULT("The root file in the ramdisk is not a folder\n");
		root = NULL;
		return RAMDISK_INVALID;		
	}
	
	// We have successfully opened the ramdisk. Return success.
	
	return SUCCESS;
}

// Given the path, open the file node representing the given path
// The path could be either a file or a folder
INT32 ramdisk_open(const INT8 * filepath, INT32 flags)
{
	FS_FileHdr *cur_dir;
	char name[MAX_FILE_NAME_SIZE];
	FS_FileHdr * search_file = NULL;
	INT32 i = 0;

	if(!filepath) {
		FAULT("ramdisk_open failed: filename argument is NULL\n");
		return -1;
	}
	
	if(!root)
	{
		FAULT("ramdisk_open failed: Ramdisk is not initialized\n");
		return -1;	
	}
	
	if(!g_current_process)
	{
		FAULT("ramdisk_open failed: This function should be called within a process\n");
		return -1;	
	}
	
	// Now get a free FILE resource for the current process
	INT32 res = GetFreeResIndex(g_rdfile_usage_mask, MAX_OPEN_FILES);
	if(res < 0) 
	{
		FAULT("ramdisk_open failed: Exhausted all %d FILE resources\n", MAX_OPEN_FILES);
		return -1;	
	}

	// Clear the FILE descriptor
	FILE * fp = &g_rdfile_pool[res];
	memset(fp, 0, sizeof(FILE));

	// Start searching from the root folder
	cur_dir = root;

	// Start parsing the filepath
	while(cur_dir)
	{
		i += getToken(name, &filepath[i]);
		
		// Look for the 'name' in the current folder
		FS_FileHdr * file = (FS_FileHdr *)((INT8*) ramdisk + cur_dir->offset);
		INT32 filecount = cur_dir->fileCount;
		while(filecount) 
		{
			if(!strcmp(file->fileName, name)) break;
			file++;	// Go to next file header
			filecount--;
		}
		
		// Did we find the folder with the given name?
		if(!filecount) {
			// We could not find the folder named 'name' in the current folder
			FAULT("ramdisk_open: Could not find folder '%s' inside '%s'\n",
							name, cur_dir->fileName);
			break;
		}
		
		// Check if we reached the end of filepath in which case, the 'file' holds the 
		// current file we are searching
		if(filepath[i] == '\x0') 
		{
			if((file->flags & F_DIR_MASK) == F_DIR) 
			{
				FAULT("ramdisk_open: the given path is not a file '%s'\n", filepath);
				break;
			}
			else 
			{
				// Found the file
				search_file = file;
				break;
			}
		}
		// The filepath parsing is not complete yet. The 'file' should be a folder
		else
		{
			if((file->flags & F_DIR_MASK) == F_DIR)
			{
				// Do Nothing
			}
			else
			{
				FAULT("ramdisk_open: '%s' in file path is not a folder\n", name);
				break;
			}		
		}
		
		cur_dir = file;
	}	
	
	if(!search_file) return -1;	// File not found

	// TODO: ISSUE #18 - Check for file permissions
	
	// Store the file attributes for this file
	fp->data = (void *)((INT8*) ramdisk + search_file->offset);
	fp->length = search_file->length;
	fp->owner = g_current_process;
	
	// Mark the resource spot as occupied
	SetResourceStatus(g_rdfile_usage_mask, res, FALSE);
	
	return res;
}

static BOOL ramdisk_assert_open(INT32 fd)
{
	// Validate the inputs
	if(fd < 0 || fd >= MAX_OPEN_FILES)
	{
		FAULT("ramdisk_assert_open: Invalid file handle\n");
		return FALSE;
	}
	
	// Check if this file is open
	if(!IsResourceBusy(g_rdfile_usage_mask, fd))
	{
		FAULT("ramdisk_assert_open failed: Invalid file handle %d. File is not open\n", fd);
		return FALSE;	
	}
	
	return TRUE;
}

INT32 ramdisk_close(INT32 fd)
{
	// Assert that the file is actually open
	if(!ramdisk_assert_open(fd)) return -1;
	
	// Assert the file ownership
	if(!ramdisk_assert_ownership(fd)) return -1;
		
	// Reset the open_files_mask
	SetResourceStatus(g_rdfile_usage_mask, fd, TRUE);

	// Reset the file structure
	memset(&g_rdfile_pool[fd], 0, sizeof(FILE));
		
	return 0;
}

INT32 ramdisk_read(INT32 fd, void * ptr, INT32 numbytes)
{
	// Assert that the file is actually open
	if(!ramdisk_assert_open(fd)) return -1;
	
	// Assert the file ownership
	if(!ramdisk_assert_ownership(fd)) return -1;

	// Get a pointer to file structure
	FILE * fp = &g_rdfile_pool[fd];
	
	INT32 read_length = ((fp->cur_offset + numbytes) <= fp->length) ? 
						numbytes : (fp->length - fp->cur_offset);
	
	memcpy(ptr, (INT8 *)fp->data + fp->cur_offset, read_length);
	fp->cur_offset += read_length;
	return read_length;
}

INT32 ramdisk_lseek(INT32 fd, INT32 position, INT32 startpoint)
{
	INT32 result = -1;
	
	// Assert that the file is actually open
	if(!ramdisk_assert_open(fd)) return -1;
	
	// Assert the file ownership
	if(!ramdisk_assert_ownership(fd)) return -1;

	// Get a pointer to file structure
	FILE * fp = &g_rdfile_pool[fd];
	
	switch(startpoint)
	{
	case SEEK_SET:
		break;			
	case SEEK_CUR:
		position += fp->cur_offset;
		break;
	case SEEK_END:
		position += fp->length;
		break;
	default:
		FAULT("ramdisk_lseek failed: Invalid file starting point %d\n", startpoint);
		return -1;
	}
	
	if((position >= 0) && (position <= fp->length))
	{
		result = fp->cur_offset = position;
	}
	
	return result;
}

static BOOL ramdisk_assert_ownership(INT32 fd)
{
	// Check the process context
	if(!g_current_process)
	{
		FAULT("ramdisk_assert_ownership failed: This function should be called within a process\n");
		return FALSE;	
	}	
	
	if(g_rdfile_pool[fd].owner != g_current_process && g_rdfile_pool[fd].owner != g_kernel_process)
	{
		FAULT("ramdisk_assert_ownership failed: This file is not owned by the current process\n");
		return FALSE;	
	}
	
	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Function to get file size
//////////////////////////////////////////////////////////////////////////////////////////
INT32 ramdisk_GetFileSize(INT32 fd)
{
	// Assert that the file is actually open
	if(!ramdisk_assert_open(fd)) return -1;
	
	// Get a pointer to file structure
	FILE * fp = &g_rdfile_pool[fd];
	
	return fp->length;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Function to get pointer to file data. Since the ramdisk already has the data in memory
// as a single contiguous block, we can return pointer to this data block.
// If the file data is not contiguous, then this function will not work
//////////////////////////////////////////////////////////////////////////////////////////
void * ramdisk_GetDataPtr(INT32 fd, UINT32 * length)
{
	// Assert that the file is actually open
	if(!ramdisk_assert_open(fd)) return NULL;
	
	// Assert the file ownership
	if(!ramdisk_assert_ownership(fd)) return NULL;
	
	// Get a pointer to file structure
	FILE * fp = &g_rdfile_pool[fd];

	// Update length 
	if(length)
	{
		*length = fp->length;
	}
	
	return fp->data;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Functions parse the file and folder names
//////////////////////////////////////////////////////////////////////////////////////////

// Function to extract the base name given the path
// Returns the number of characters consumed
static INT32 getToken(INT8 * dst, const INT8 * path)
{
	INT32 i = 0;
	INT32 j = 0;
	if(!dst || !path)
	{
		FAULT("ERROR: getBaseFolderName: Argument error\n");
		return -1;	
	}
	
	// Ignore the first '/' if one exists
	if(path[0] == '/') i++;
	
	// Allow only alpha numeric characters, '.', '_' in the file/folder names
	while(path[i] != '/' && path[i] != '\x0')
	{
		dst[j++] = path[i++];
	}
	
	dst[j++] = '\x0';
	
	return i;	// Return the number of characters consumed;	
}
