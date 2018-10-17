section .text align=16
global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	push rdi
	push rsi

	.test_init:
		cmp rdi, 0
		jne .start_copy
		cmp rsi, 0
		je .end


	.start_copy:
		cld
		mov rcx, rdx
		rep movsb

	.end:
		pop rdi
		pop rsi
		mov rax, rsi
		mov rsp, rbp
		pop rbp
		ret
