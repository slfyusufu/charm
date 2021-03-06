///////////////////////////////////////////////////////////////////////////////
//	
//						Copyright 2009-2013 xxxxxxx, xxxxxxx
//	File:	os_task.h
//	Author:	Bala B. (bhat.balasubramanya@gmail.com)
//	Description: OS Task Related routines
//	
///////////////////////////////////////////////////////////////////////////////

#include "os_types.h"

#ifndef _OS_TASK_H
#define _OS_TASK_H

#if OS_WITH_VALIDATE_TASK==1
#define TASK_SIGNATURE	0xFEEDBACC
#endif

///////////////////////////////////////////////////////////////////////////////
// Helper Macros for Task Types, Modes and associated functions
///////////////////////////////////////////////////////////////////////////////
enum 
{
	APERIODIC_TASK 		= 0,
	PERIODIC_TASK 		= 1,
	TASK_MODE_MASK		= 1,
	
	SYSTEM_TASK			= 2,
	USER_TASK			= 0,
	TASK_PRIVILEGE_MASK	= 2
};

#define IS_PERIODIC_TASK(task_attr)		(((task_attr) & TASK_MODE_MASK) == PERIODIC_TASK)
#define IS_APERIODIC_TASK(task_attr)	(((task_attr) & TASK_MODE_MASK) == APERIODIC_TASK)

#define IS_SYSTEM_TASK(task_attr)	(((task_attr) & TASK_PRIVILEGE_MASK) == SYSTEM_TASK)
#define IS_USER_TASK(task_attr)		(((task_attr) & TASK_PRIVILEGE_MASK) == USER_TASK)

///////////////////////////////////////////////////////////////////////////////
// Task TCB 
///////////////////////////////////////////////////////////////////////////////
struct OS_Process;

typedef struct OS_PeriodicTask OS_PeriodicTask;
struct OS_PeriodicTask
{
	// Attributes for maintaining a list/queue of threads.
	// IMPORTANT: Make sure that the below two attributes are the first two
	// attributes in the same order. This is done so that we can have a single
	// queue implementation for all types of objects as long as the below two
	// members are part of those objects.
	OS_PeriodicTask * next;	// Do NOT REORDER THESE TWO MEMBERS
	UINT64 alarm_time;	// To be used for maintaining a queue ordered based on this key value

	UINT32 *top_of_stack;	// Do NOT REORDER THIS MEMBER, THE OFFSET 'SP_OFFSET_IN_TCB' IS USED IN ASSEMBLY
	struct OS_Process *owner_process;	// Do NOT REORDER THIS MEMBER, THE OFFSET 'OWNER_OFFSET_IN_TCB' IS USED IN Assembly

	UINT32 *stack;
	UINT32 stack_size;
	void (*task_function)(void *pdata);
	void *pdata;
	
	void *syscall_result;		// Some syscalls put the thread to wait. This member holds a pointer to its return argiments
	UINT64 accumulated_budget;

	// Folliwing attributes are common in both type of tasks. They should be in the same order.
	UINT16 attributes;
	UINT16 id;
	INT8 name[OS_TASK_NAME_SIZE];
#if OS_WITH_VALIDATE_TASK==1
	UINT32 signature;		// A unique identifier to validate the task structure
#endif	// OS_WITH_VALIDATE_TASK
	
	// Following arguments are specific to Periodic task
	UINT32 period;
	UINT32 deadline;
	UINT32 budget;
	UINT32 phase;
	
	// Following members are used by the scheduling algorithm
	UINT32 remaining_budget;
    
    // When the task is in the wait_queue, it will have its job_release_time as the next release time
    // When it is in the ready queue, it is the task period beginning value for the current period
    UINT64 job_release_time;
	UINT32 exec_count;
	UINT32 TBE_count;
	UINT32 dline_miss_count;
};

typedef struct OS_AperiodicTask OS_AperiodicTask;
struct OS_AperiodicTask
{
	// Attributes for maintaining a list/queue of threads.
	// IMPORTANT: Make sure that the below two attributes are the first two
	// attributes in the same order. This is done so that we can have a single
	// queue implementation for all types of objects as long as the below two
	// members are part of those objects.
	OS_AperiodicTask * next;	// Do NOT REORDER THESE TWO MEMBERS
	UINT64 priority;	// To be used for maintaining a queue ordered based on this key value

	// Folliwing attributes are common in both type of tasks. They should be in the same order
	UINT32 *top_of_stack;	// Do NOT REORDER THIS MEMBER, THE OFFSET 'SP_OFFSET_IN_TCB' IS USED IN Assembly
	struct OS_Process *owner_process;	// Do NOT REORDER THIS MEMBER, THE OFFSET 'OWNER_OFFSET_IN_TCB' IS USED IN Assembly

	UINT32 *stack;
	UINT32 stack_size;
	void (*task_function)(void *pdata);
	void *pdata;
	
	void *syscall_result;		// Some syscalls put the thread to wait. This member holds a pointer to its return argiments
	UINT64 accumulated_budget;

	UINT16 attributes;
	UINT16 id;
	INT8 name[OS_TASK_NAME_SIZE];
#if OS_WITH_VALIDATE_TASK==1
	UINT32 signature;		// A unique identifier to validate the task structure
#endif	// OS_WITH_VALIDATE_TASK	
};

typedef union OS_GenericTask
{
	struct
	{
		// Attributes for maintaining a list/queue of threads.
		// IMPORTANT: Make sure that the below two attributes are the first two
		// attributes in the same order. This is done so that we can have a single
		// queue implementation for all types of objects as long as the below two
		// members are part of those objects.
		union OS_GenericTask * next;	// Do NOT REORDER THESE TWO MEMBERS
		UINT64 key;	// To be used for maintaining a queue ordered based on this key value

		// Folliwing attributes are common in both type of tasks. They should be in the same order
		UINT32 *top_of_stack;	// Do NOT REORDER THIS MEMBER, THE OFFSET 'SP_OFFSET_IN_TCB' IS USED IN Assembly
		struct OS_Process *owner_process;	// Do NOT REORDER THIS MEMBER, THE OFFSET 'OWNER_OFFSET_IN_TCB' IS USED IN Assembly

		UINT32 *stack;
		UINT32 stack_size;
		void (*task_function)(void *pdata);
		void *pdata;

		UINT32 *syscall_result;		// Some syscalls put the thread to wait. This member holds a pointer to its return argiments
		UINT64 accumulated_budget;

		UINT16 attributes;
		UINT16 id;
		INT8 name[OS_TASK_NAME_SIZE];
	#if OS_WITH_VALIDATE_TASK==1
		UINT32 signature;		// A unique identifier to validate the task structure
	#endif	// OS_WITH_VALIDATE_TASK
	};
	
	OS_PeriodicTask 	periodic;
	OS_AperiodicTask	aperiodic;

} OS_GenericTask;

OS_Return _OS_CreatePeriodicTask(
	UINT32 period_in_us,
	UINT32 deadline_in_us,
	UINT32 budget_in_us,
	UINT32 phase_shift_in_us,
	UINT32 *stack,
	UINT32 stack_size_in_bytes,
	const INT8 * task_name,
	UINT16 options,
	OS_Task_t *task,
	void (*periodic_entry_function)(void *pdata),
	void *pdata);

OS_Return _OS_CreateAperiodicTask(UINT16 priority, 
	UINT32 * stack, 
	UINT32 stack_size_in_bytes,
	const INT8 * task_name,
	UINT16 options,
	OS_Task_t * task,
	void(* task_entry_function)(void * pdata),
	void * pdata);

OS_Return _OS_GetTaskAllocMask(UINT32 * alloc_mask, UINT32 count, UINT32 starting_task);

// Placeholders for all the process control blocks
extern OS_GenericTask	g_task_pool[MAX_TASK_COUNT];
extern UINT32 			g_task_usage_mask[];

#endif // _OS_TASK_H
