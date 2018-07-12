/***************************************************
*		 Copyright (c) 2018 MINE 田宇
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of version 2 of the GNU General Public
* License as published by the Free Software Foundation.
*
***************************************************/


#include "errno.h"
#include "printk.h"

/*
normal
system call number:	rax
arg1:	rdi
arg2:	rsi
arg3:	rdx
arg4:	rcx
arg5:	r8
arg6:	r9

sysenter need rdx(rip) rcx(rsp)
syscall need rcx(rip) r11(rflags)

xchg rdx to r10, rcx to r11

*/

unsigned long no_system_call(void)
{
	color_printk(RED,BLACK,"no_system_call is calling\n");
	return -ENOSYS;
}

/*	
__asm__	(
".global puts	\n\t"
".type	puts,	@function \n\t"
"puts:		\n\t"
"pushq	%r10	\n\t"
"pushq	%r11	\n\t"
"movq	$__NR_puts	,	%rax	\n\t"
"leaq	sysexit_return_address(%rip),	%r10	\n\t"
"movq	%rsp,	%r11		\n\t"
"sysenter			\n\t"
"sysexit_return_address:	\n\t"
"xchgq	%rdx,	%r10	\n\t"
"xchgq	%rcx,	%r11	\n\t"
"popq	%r11	\n\t"
"popq	%r10	\n\t"
);	
*/


unsigned long sys_putstring(char *string)
{
	color_printk(ORANGE,WHITE,string);
	return 0;
}





