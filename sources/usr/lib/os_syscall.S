//------------------------------------------------------------------------------
//
//						Copyright 2013 xxxxxxx, xxxxxxx
//	File:	os_syscall.S
//	Author: Bala B. (bhat.balasubramanya//gmail.com)
//	Description: Assembly routine that makes a system call
//
//-------------------------------------------------------------------------------

SYSCALL_BASIC     = 0x0
SYSCALL_SWITCHING = 0x1

   	.section .text
   	.code 32

//---------------------------------------------------------------------
// Assembly routine that makes the system call which does not result in context switches
// OS_Return _OS_Syscall(const _OS_Syscall_Args * param_info, 
//						const void * arg, void * ret, Syscall_type type)
//---------------------------------------------------------------------
	.global _OS_Syscall
_OS_Syscall:

    push    {fp, lr}
    add     fp, sp, #4

	teq     r3, #SYSCALL_SWITCHING      // Check what type of system call this is
	svceq	0x1							// Call SVC 0x1 with parameter value in R0
	svcne	0x0							// Call SVC 0x0 with parameter value in R0

    pop     {fp, pc}
