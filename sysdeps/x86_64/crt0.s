.section .text

.global _start
_start:
	movq $0, %rbp
	pushq %rbp # rip=0
	pushq %rbp # rbp=0
	movq %rsp, %rbp
	pushq %rsi
	pushq %rdi
	call initialize_standard_library
	call _init
	popq %rdi
	popq %rsi
	call main
	movl %eax, %edi
	call exit
.size _start, . - _start
