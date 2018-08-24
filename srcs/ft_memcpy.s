section .text align=16
global _ft_memcpy

_ft_memcpy:
	push rbp
	mov rbp, rsp

	push rdi
	push rsi

	.test_init:
		cmp rdi, 0
		jne .start_copy
		cmp rsi, 0
		je .end


	.start_copy: 
		xor rcx, rcx
		.copy:
			cmp rcx, rdx
				je .end
			mov al, [rsi]
			mov [rdi], al
			inc rcx
			inc rsi
			inc rdi
		jmp .copy

	.end:
		pop rdi
		pop rsi
		mov rax, rsi
		mov rsp, rbp
		pop rbp
		ret