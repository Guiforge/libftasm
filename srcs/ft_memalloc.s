section .text align=16
global _ft_memalloc
extern _ft_bzero
extern _malloc

_ft_memalloc:
	push rbp
	mov rbp, rsp
	push r9

	mov r8, rdi
	push r8
	call _malloc
	pop r8
	mov r9, rax
	cmp rax, 0
	je .end

	mov rdi, rax
	mov rsi, r8
	call _ft_bzero


	.end:
		mov rax, r9
		pop r9
		mov rsp, rbp
		pop rbp
		ret
