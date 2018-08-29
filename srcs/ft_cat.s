%define STDOUT				1
%define READ				3
%define WRITE				4
%define MACH_SYSCALL(x)		0x2000000 | x
%define BUF_SIZE			1025

section .bss align=16
buffer resb 1025

section .text align=16
global _ft_cat


_ft_cat:
	push rsp
	mov rsp, rbp

	lea rsi, [rel buffer]
	mov r8, rdi

	.loop:
		;READ
		mov rdi, r8
		mov rdx, BUF_SIZE
		mov rax, MACH_SYSCALL(READ)
		syscall
		jc .end
		cmp rax, 0
		jle .end

		;WRITE
		mov rdi, STDOUT
		mov rdx, rax
		mov rax, MACH_SYSCALL(WRITE)
		syscall
		jc .end
		cmp rax, 0
		jle .end
	jmp .loop
	
	.end:
		mov rsp, rbp
		pop rbp
		ret

