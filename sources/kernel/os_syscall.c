///////////////////////////////////////////////////////////////////////////////
//
//						Copyright 2013 xxxxxxx, xxxxxxx
//	File:	os_syscall.c
//	Author: Bala B.
//	Description: Kernel Mode implementation of system calls
//
///////////////////////////////////////////////////////////////////////////////

#include "os_core.h"
#include "os_sem.h"
#include "os_stat.h"
#include "os_driver.h"
#include "../usr/includes/os_syscall.h"

//////////////////////////////////////////////////////////////////////////////
// Function prototypes
//////////////////////////////////////////////////////////////////////////////
static void syscall_PeriodicTaskCreate(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_AperiodicTaskCreate(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_ProcessCreate(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_ProcessCreateFromFile(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_SemAlloc(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_SemWait(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_SemPost(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_SemFree(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_SemGetValue(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_GetCurTask(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_TaskYield(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_SetUserLED(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_OSGetStat(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_TaskGetStat(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_SerialLog(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_GetTaskAllocMask(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_DriverStandardCall(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static void syscall_DriverCustomCall(const _OS_Syscall_Args * param_info, const void * arg, void * ret);

//////////////////////////////////////////////////////////////////////////////
// Other function prototypes
//////////////////////////////////////////////////////////////////////////////
void _OS_TaskYield(void);
OS_Return _PFM_SetUserLED(LED_Number led, LED_Options options);
UINT32 _PFM_SerialLog(const INT8 * str, UINT32 size);
OS_Return _OS_GetTaskAllocMask(UINT32 * alloc_mask, UINT32 count, UINT32 starting_task);

OS_GenericTask * g_current_task;

//////////////////////////////////////////////////////////////////////////////
// Vector containing all syscall handlers
//////////////////////////////////////////////////////////////////////////////
typedef void (*Syscall_handler)(const _OS_Syscall_Args * param_info, const void * arg, void * ret);
static Syscall_handler _syscall_handlers[SYSCALL_MAX_COUNT] = {
		
		// The order of these functions should match the order of enums in os_syscall.h
		syscall_PeriodicTaskCreate,
		syscall_AperiodicTaskCreate,
		syscall_ProcessCreate,
		syscall_ProcessCreateFromFile,
		syscall_SemAlloc,
		syscall_SemWait,
		syscall_SemPost,
		syscall_SemFree,
		syscall_SemGetValue,
		syscall_GetCurTask,
		syscall_TaskYield, 
		syscall_OSGetStat,
		syscall_TaskGetStat,
		syscall_SerialLog,
		syscall_GetTaskAllocMask,
		0, 
		0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0, 
		0, 0, 0, 0, 0,
		0, syscall_SetUserLED
	};

///////////////////////////////////////////////////////////////////////////////
// Kernel Side of the Syscall function
///////////////////////////////////////////////////////////////////////////////
void _OS_KernelSyscall(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{	
	if(!param_info || (param_info->id >= SYSCALL_MAX_COUNT) || !_syscall_handlers[param_info->id])
	{
		KlogStr(KLOG_WARNING, "Error occurred in Kernel function %s", __FUNCTION__);
		if(ret) ((UINT32 *)ret)[0] = SYSCALL_ERROR;
		return;
	}
	
	// Note down the result pointer which may be needed
	if(g_current_task) g_current_task->syscall_result = (UINT32 *)ret;
	_syscall_handlers[param_info->id](param_info, arg, ret);
}

static void syscall_PeriodicTaskCreate(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	UINT32 * uint_ret = (UINT32 *)ret;
	OS_Return result = SYSCALL_ERROR;
	
	if(((param_info->arg_bytes >> 2) >= 9) && ((param_info->ret_bytes >> 2) >= 2))
	{	
		result = _OS_CreatePeriodicTask((UINT32)uint_args[0],
									(UINT32)uint_args[1],
									(UINT32)uint_args[2],
									(UINT32)uint_args[3],
									(UINT32 *)uint_args[4],
									(UINT32)uint_args[5],
									(INT8 *)uint_args[6],
									USER_TASK,
									(OS_Task_t *)(uint_ret+1),
									(void *)uint_args[7],
									(void *)uint_args[8]);
	}
								
	if(uint_ret) uint_ret[0] = result;
}

static void syscall_TaskYield(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	_OS_TaskYield();
}

static void syscall_AperiodicTaskCreate(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	UINT32 * uint_ret = (UINT32 *)ret;
	OS_Return result = SYSCALL_ERROR;
	
	if(((param_info->arg_bytes >> 2) >= 6) && ((param_info->ret_bytes >> 2) >= 2))
	{
		result = _OS_CreateAperiodicTask((UINT32)uint_args[0],
								(UINT32 *)uint_args[1],
								(UINT32)uint_args[2],
								(INT8 *)uint_args[3],
								USER_TASK,
								(OS_Task_t *)(uint_ret+1),
								(void *)uint_args[4],
								(void *)uint_args[5]);
	}
	
	if(uint_ret) uint_ret[0] = result;
}

static void syscall_ProcessCreate(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	if(ret) ((UINT32 *)ret)[0] = SYSCALL_ERROR;
}

static void syscall_ProcessCreateFromFile(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	if(ret) ((UINT32 *)ret)[0] = SYSCALL_ERROR;
}

static void syscall_SemAlloc(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	UINT32 * uint_ret = (UINT32 *)ret;
	OS_Return result = SYSCALL_ERROR;
	
	if(((param_info->arg_bytes >> 2) >= 1) && ((param_info->ret_bytes >> 2) >= 2))
	{
		result = _OS_SemAlloc((OS_Sem_t *)(uint_ret+1), uint_args[0]);
	}
	
	if(uint_ret) uint_ret[0] = result;
}

static void syscall_SemWait(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	OS_Return result = SYSCALL_ERROR;
	
	if((param_info->arg_bytes >> 2) >= 1)
	{		
		result = _OS_SemWait(uint_args[0]);
	}
	
	if(ret) ((UINT32 *)ret)[0] = result;
}

static void syscall_SemPost(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	OS_Return result = SYSCALL_ERROR;
	
	if((param_info->arg_bytes >> 2) >= 1)
	{
		result = _OS_SemPost(uint_args[0]);
	}
	
	if(ret) ((UINT32 *)ret)[0] = result;
}

static void syscall_SemFree(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	OS_Return result = SYSCALL_ERROR;
	
	if((param_info->arg_bytes >> 2) >= 1)
	{
		result = _OS_SemFree(uint_args[0]);
	}
	
	if(ret) ((UINT32 *)ret)[0] = result;
}

static void syscall_SemGetValue(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	UINT32 * uint_ret = (UINT32 *)ret;
	OS_Return result = SYSCALL_ERROR;
	
	if(((param_info->arg_bytes >> 2) >= 1) && ((param_info->ret_bytes >> 2) >= 2))
	{
		_OS_SemGetValue(uint_args[0], (uint_ret+1));
	}
	
	if(uint_ret) uint_ret[0] = result;
}

static void syscall_GetCurTask(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	// TODO: Implement this function
}

///////////////////////////////////////////////////////////////////////////////
// Function: PFM_SetUserLED
// The mask indicates which LEDs should be turned ON/OFF/Toggled depending on 
// the options provided
///////////////////////////////////////////////////////////////////////////////
static void syscall_SetUserLED(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	
	if((param_info->arg_bytes >> 2) >= 2)
	{
		_PFM_SetUserLED((UINT32)uint_args[0], (UINT32)uint_args[1]);
	}
}

///////////////////////////////////////////////////////////////////////////////
// Serial logging function
///////////////////////////////////////////////////////////////////////////////
static void syscall_SerialLog(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	const UINT32 * uint_args = (const UINT32 *)arg;
	UINT32 * uint_ret = (UINT32 *)ret;
	UINT32 result = 0;
	
	if(((param_info->arg_bytes >> 2) >= 2) && ((param_info->ret_bytes >> 2) >= 1))
	{
		result = _PFM_SerialLog((const INT8 *)uint_args[0], uint_args[1]);
	}
	
	if(uint_ret) uint_ret[0] = result;
}

///////////////////////////////////////////////////////////////////////////////
// Statistics functions
///////////////////////////////////////////////////////////////////////////////
static void syscall_OSGetStat(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	UINT32 * uint_ret = (UINT32 *)ret;
	
#if OS_ENABLE_CPU_STATS==1	
	const UINT32 * uint_args = (const UINT32 *)arg;
	OS_Return result = SYSCALL_ERROR;

	if(((param_info->arg_bytes >> 2) >= 1) && ((param_info->ret_bytes >> 2) >= 1))
	{
		result = _OS_GetStatCounters((OS_StatCounters *)uint_args[0]);
	}
	
	if(uint_ret) uint_ret[0] = result;
#else
	if(uint_ret) uint_ret[0] = NOT_CONFIGURED;	
#endif
}

static void syscall_TaskGetStat(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	UINT32 * uint_ret = (UINT32 *)ret;
#if OS_ENABLE_CPU_STATS==1
	const UINT32 * uint_args = (const UINT32 *)arg;
	OS_Return result = SYSCALL_ERROR;
	
	if(((param_info->arg_bytes >> 2) >= 2) && ((param_info->ret_bytes >> 2) >= 1))
	{
		result = _OS_GetTaskStatCounters((OS_Task_t )uint_args[0], (OS_TaskStatCounters *)uint_args[1]);
	}
	
	if(uint_ret) uint_ret[0] = result;
#else
	if(uint_ret) uint_ret[0] = NOT_CONFIGURED;	
#endif	
}

static void syscall_GetTaskAllocMask(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
	UINT32 * uint_ret = (UINT32 *)ret;
#if OS_ENABLE_CPU_STATS==1
	const UINT32 * uint_args = (const UINT32 *)arg;
	OS_Return result = SYSCALL_ERROR;
	
	if(((param_info->arg_bytes >> 2) >= 3) && ((param_info->ret_bytes >> 2) >= 1))
	{
		result = _OS_GetTaskAllocMask((UINT32 *)uint_args[0], uint_args[1], uint_args[2]);
	}
	
	if(uint_ret) uint_ret[0] = result;
#else
	if(uint_ret) uint_ret[0] = NOT_CONFIGURED;	
#endif
}

static void syscall_DriverStandardCall(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
    const INT8 * str_args = (const INT8 *)arg;
    const UINT32 * uint_args = (const UINT32 *)arg;
	UINT32 * uint_ret = (UINT32 *)ret;
	OS_Return result = SYSCALL_ERROR;
	
	switch(param_info->sub_id)
	{
    case SUBCALL_DRIVER_LOOKUP:
        if(((param_info->arg_bytes >> 2) >= 1) && ((param_info->ret_bytes >> 2) >= 2))
        {
        	result = _OS_DriverLookup(str_args[0], (OS_Driver_t *)(uint_ret+1));
        }
        break;
        
    case SUBCALL_DRIVER_OPEN:
        if(((param_info->arg_bytes >> 2) >= 2) && ((param_info->ret_bytes >> 2) >= 1))
        {
        	result = _OS_DriverOpen((OS_Driver_t) uint_args[0], (OS_DriverAccessMode) uint_args[1]);
        }
        break;
            
    case SUBCALL_DRIVER_CLOSE:
        if(((param_info->arg_bytes >> 2) >= 1) && ((param_info->ret_bytes >> 2) >= 1))
        {
        	result = _OS_DriverClose((OS_Driver_t) uint_args[0]);
        }
        break;
            
    case SUBCALL_DRIVER_READ:
        
        break;
        
    case SUBCALL_DRIVER_WRITE:
        
        break;
        
    case SUBCALL_DRIVER_CONFIGURE:
    
        break;
	}
	
	if(uint_ret) uint_ret[0] = result;
}

static void syscall_DriverCustomCall(const _OS_Syscall_Args * param_info, const void * arg, void * ret)
{
}
