section .text align=16
global _ft_memalloc
extern _ft_bzero
extern _malloc
extern _memset

_ft_memalloc:
	push rbp
	mov rbp, rsp
	sub rsp, 32

	push r9
	push rdi

	call _malloc

	mov r9, rax
	cmp rax, 0
	je .end
	pop rdi

	mov rsi, rdi
	mov rdi, rax
	call _ft_bzero


	.end:
		mov rax, r9
		pop r9
		mov rsp, rbp
		pop rbp
		ret
