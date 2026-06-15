.section .text

.global _start
_start:
	xorq %rbp, %rbp

	movl (%rsp), %edi
	leaq 8(%rsp), %rsi
	subq $8, %rsp
	pushq %rsi
	pushq %rdi
	call libc_init
	call _init

	popq %rdi
	popq %rsi

	call main
	movl %eax, %edi
	call exit
	
.hang:
	hlt
	jmp .hang

.size _start, . - _start
