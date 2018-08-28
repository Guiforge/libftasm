section .text align=16

global _ft_strcpy
extern _ft_strlen
extern _ft_memcpy

_ft_strcpy:
	push rbp
	mov rbp, rsp

	push r8
	push r9
	mov r8, rdi
	mov rdi, rsi
	call _ft_strlen
	mov r9, rax

	mov rdi, r8
	mov rdx, rax
	call _ft_memcpy

	.end:
		pop r8
		pop r9
		mov rsp, rbp
		pop rbp
		ret