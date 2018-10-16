section .text align=16
global _ft_memset

_ft_memset:
	push rbp
	mov rbp, rsp

	push rdi
	push rcx

	mov rcx, rdx
	mov rax, rsi
	cld
	rep stosb

	pop rcx
	pop rdi

.end:
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret