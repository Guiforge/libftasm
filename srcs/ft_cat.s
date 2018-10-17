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

	; prologue
	push rbp
	mov rbp, rsp
	sub rsp, 16

	push rdx
	push rsi
	push rdi
	push r8

	mov r8, rdi
	.loop:
		mov rdi, r8
		lea rsi, [rel buffer]
		mov rdx, BUF_SIZE
		mov rax, MACH_SYSCALL(READ)
		syscall
		jc .error
		cmp rax, 0
		je .end

		mov rdi, STDOUT
		mov rdx, rax
		mov rax, MACH_SYSCALL(WRITE)
		syscall
		jc .error
	jmp .loop



	.end:
		pop rdx
		pop rsi
		pop rdi
		mov rsp, rbp
		pop rbp
		ret

	.error:
		; pop rdi
		mov rax, 1
		jmp .end

