section .text align=16

global _ft_strncpy
extern _ft_strlen
extern _ft_memcpy

_ft_strncpy:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	push r8
	push r9
	mov r8, rdi
	mov rdi, rsi
	call _ft_strlen
	inc rax
	mov r9, rax
	cmp rax, rdx 
	jl .lower

	.copy:
		mov rdi, r8
		call _ft_memcpy

	.end:
		pop r8
		pop r9
		mov rsp, rbp
		pop rbp
		ret

	.lower:
		mov rdx, rax
		jmp .copy
