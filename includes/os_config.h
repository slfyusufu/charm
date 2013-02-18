///////////////////////////////////////////////////////////////////////////////
//	
//						Copyright 2009-2013 xxxxxxx, xxxxxxx
//	File:	os_config.h
//	Author:	Bala B. (bhat.balasubramanya@gmail.com)
//	Description: OS Configuration options
//	
///////////////////////////////////////////////////////////////////////////////

#ifndef _OS_CONFIG_H
#define _OS_CONFIG_H

#define FIN 	(12000000)			// 12MHz Crystal

#define FCLK (405000000)			// Main Processor clock	405 MHz
#define HCLK (FCLK/3)				// AHB Clock	135 MHz
#define PCLK (HCLK/2)				// APB Clock	67.5 MHz
#define UCLK (48000000)				// USB Clock

#define	TIMER_PRESCALAR_0	(0x3f)	// PCLK/64
#define	TIMER0_DIVIDER		(0x00)	// PCLK/PRESCALAR0/2
#define	TIMER1_DIVIDER		(0x00)	// PCLK/PRESCALAR0/2
#define	TIMER01_TICK_RATE	(PCLK/(TIMER_PRESCALAR_0+1)/2)		// Resolution 1.8963 uSec per tick

// (65535 * 1000000) / TIMER01_TICK_RATE = 124273.78 uSec. Lets use 100ms for this.
// This way there will be at least one interrupt every 100ms
#define	MAX_TIMER0_INTERVAL_uS	100000		

// (65535 * 1000000) / TIMER01_TICK_RATE = 124273.78 uSec. Lets use 120ms for this.
// Note that this value should be > MAX_TIMER0_INTERVAL_uS in order to prevent race between
// timer0 & timer1 interrupts. 
#define	MAX_TIMER1_INTERVAL_uS	120000		

// Instruction and Data Cache related
#define ENABLE_INSTRUCTION_CACHE	1
#define ENABLE_DATA_CACHE			1

// Drivers to include
#define ENABLE_RTC					1
#define ENABLE_RTC_ALARM			1

// Task related configuration parameters
#define MIN_PRIORITY				255
#define OS_IDLE_TASK_STACK_SIZE		0x40		// In Words
#define OS_STAT_TASK_STACK_SIZE		0x40		// In Words
#define OS_WITH_TASK_NAME			1
#define OS_TASK_NAME_SIZE			8

// Time for the first scheduling interrupt to begin. This should be <= MAX_TIMER0_INTERVAL_uS
#define OS_FIRST_SCHED_DELAY		10000

// Following values depend a lot on the timer resolution which is not very good in this case
#define TASK_MIN_PERIOD		100	// 100 uSec
#define TASK_MIN_BUDGET		100 // 100 uSec
#define TIME_RESOLUTION_IN_US	250	// 250uSec

// TODO: I should handle the case where these are bigger values. Should be possible by taking care while setting 
// timers
#define TASK_MAX_BUDGET		MAX_TIMER1_INTERVAL_uS

// Debug & Info related

// Define the Debug masks
typedef enum
{
	KLOG_CONTEXT_SWITCH 	= (1 << 0),
	KLOG_OS_TIMER_ISR 		= (1 << 1),
	KLOG_BUDGET_TIMER_ISR 	= (1 << 2),
	KLOG_DEBUG_BUDGET 		= (1 << 3),
	KLOG_OS_TIMER_SET 		= (1 << 4),
	KLOG_BUDGET_TIMER_SET 	= (1 << 5),
	
	KLOG_MISC 				= (1 << 31)
	
} Klog_MaskType;

#define OS_ENABLE_CPU_STATS			0		// TODO: Enable CPU Stats
#define OS_WITH_VALIDATE_TASK		1
#define	OS_KERNEL_LOGGING			0
#define	OS_KLOG_MASK				(KLOG_OS_TIMER_SET)
#define DEBUG_UART_CHANNEL			0

#endif // _OS_CONFIG_H
