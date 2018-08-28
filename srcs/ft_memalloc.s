section .text align=16
global _ft_memalloc
extern _ft_memset
extern _malloc

_ft_memalloc:
	push rbp
	mov rbp, rsp
	push r8

	mov r8, rdi
	call _malloc
	cmp rax, 0
	je .end

	mov rdi, rax
	mov rsi, 0
	mov rdx, r8
	call _ft_memset


	.end:
		pop r8
		mov rsp, rbp
		pop rbp
		ret