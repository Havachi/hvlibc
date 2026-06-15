#ifndef _X86_64_SYSDEPS_H
#define _X86_64_SYSDEPS_H 1
#include "syscall-ids.h"
#include "../x86/sysdep.h"

#ifdef __ASSEMBLER__
# define cfi_offset_rel_rsp(regn, off) .cfi_escape 0x10, regn, 0x4, 0x13, \
	0x77, off & 0x7F | 0x80, off >> 7

#undef PSEUDO
#define PSEUDO (name, syscall_name, args) \
.text
ENTRY (name)
	DO_CALL (syscall_name, args); \
	cmpq $-4095, %rax; \
	jae SYSCALL_ERROR_LABEL

#undef PSEUDO_END
#define PSEUDO_END(name) \
	SYSCALL_ERROR_HANDLER \
	END(name) 

#undef PSEUDO_NOERROR
#define PSEUDO_NOERROR(name, syscall_name, args) \
	END(name)

#define ret_NOERROR ret

#undef PSEUDO_ERRVAL
#define PSEUDO_ERRVAL(name, syscall_name, args) \
.text \
ENTRY(name) \
	DO_CALL(syscall_name, args) \
	negq %rax

#undef PSEUDO_END_ERRVAL
#define PSEUDO_END_ERRVAL(name) \
	END(name)

#define ret_ERRVAL ret

#undef DO_CALL
#define DO_CALL(syscall_name, args) \
	DOARGS_##args \
	movl syscall_name, %eax; \
	syscall;

#define DOARGS_0
#define DOARGS_1
#define DOARGS_2
#define DOARGS_3
#define DOARGS_4	movq %rcx, %r10;
#define DOARGS_5	DOARGS_4
#define DOARGS_6	DOARGS_5

#undef JUMPTARGET

#ifdef SHARED
# ifdef BIND_NOW
#  define JUMPTARGET(name) *name##@GOTPCREL(%rip)
# else
#  define JUMPTARGET(name) *name##@PLT
# endif
#else
# define JUMPTARGET(name) name
#endif

#define LP_SIZE 8
#define LP_OP(insn) insn##q
#define ASM_ADDR .quad

#define RAX_LP	rax
#define RBP_LP	rbp
#define RBX_LP	rbx
#define RCX_LP	rcx
#define RDI_LP	rdi
#define RDX_LP	rdx
#define RSI_LP	rsi
#define RSP_LP	rsp
#define R8_LP	r8
#define R9_LP	r9
#define R10_LP	r10
#define R11_LP	r11
#define R12_LP	r12
#define R13_LP	r13
#define R14_LP	r14
#define R15_LP	r15

#else

#define LP_SIZE "8"
#define LP_OP(insn) #insn "q"
#define ASM_ADDR ".quad"

#define RAX_LP	"rax"
#define RBP_LP	"rbp"
#define RBX_LP	"rbx"
#define RCX_LP	"rcx"
#define RDI_LP	"rdi"
#define RDX_LP	"rdx"
#define RSI_LP	"rsi"
#define RSP_LP	"rsp"
#define R8_LP	"r8"
#define R9_LP	"r9"
#define R10_LP	"r10"
#define R11_LP	"r11"
#define R12_LP	"r12"
#define R13_LP	"r13"
#define R14_LP	"r14"
#define R15_LP	"r15"

#undef INLINE_SYSCALL
#define INLINE_SYSCALL(name, nr, args...) \
	({ \
		unsigned long int resultvar= INTERNAL_SYSCALL(name, , nr, args); \
		if (__hvlibc_unlikely(INTERNAL_SYSCALL_ERROR_P (resultvar, ))) \
		{ \
			__set_errno(INTERNAL_SYSCALL_ERRNO (resultvar,)); \
			resultvar = (unsigned long int) -1; \
		} \
		(long int )resultvar; }) 


#define __syscall1(num, arg1) ({					\
		long _ret;									\
		__asm__ __volatile__(						\
			"syscall"								\
			: "=a"(_ret)							\
			: "a"((long)(num)) , "D"((long)(arg1))	\
			: "rcx", "r11", "memory"				\
		);											\
		_ret;										\
})

#define __syscall2(num, arg1, arg2) ({				\
		long _ret;									\
		__asm__ __volatile__(						\
			"syscall"								\
			: "=a"(_ret)							\
			: "a"((long)(num)) , "D"((long)(arg1)), "S"((long)(arg2))	\
			: "rcx", "r11", "memory"				\
		);											\
		_ret;										\
})

#define __syscall3(num, arg1, arg2, arg3) ({	\
	long _ret;									\
	__asm__ __volatile__(						\
		"syscall"								\
		: "=a"(_ret)							\
		: "a"((long)(num)), "D"((long)(arg1)), "S"((long)(arg2)), "d"((long)(arg3)) \
		: "rcx", "r11", "memory"				\
	);											\
	_ret;										\
})



#endif /* __ASSEMBLER__ */

#endif /* _X86_64_SYSDEPS_H */