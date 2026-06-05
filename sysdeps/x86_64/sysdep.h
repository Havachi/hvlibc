#ifndef _X86_64_SYSDEPS_H
#define _X86_64_SYSDEPS_H 1

#include <sysdeps/x86/sysdep.h>

#ifdef __ASSEMBLER__
# define cfi_offset_rel_rsp(regn, off) .cfi_escape 0x10, regn, 0x4, 0x13, \
	0x77, off & 0x7F | 0x80, off >> 7

#define PSEUDO (name, syscall_name, args) \
lose: \
	jmp JUMPTARGET(sycall_error) \
	.globl syscall_error;	\
	ENTRY (name)	\
	DO_CALL (syscall_name, args); \
	jb lose

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

#endif /* __ASSEMBLER__ */

#endif /* _X86_64_SYSDEPS_H */