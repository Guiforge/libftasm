section .text align=16
extern _ft_strlen
extern _ft_memalloc
extern _ft_strcpy
global _ft_strdup

;rdi, rsi rdx
_ft_strdup:
	push rbp
	mov rbp, rsp
	push r8

	mov r8, rdi
	call _ft_strlen
	mov r9, rax
	inc r9


	mov rdi, r9
	call _ft_memalloc
	cmp rax, 0
	je .end

	mov rdi, rax
	mov rsi, r8
	call _ft_strcpy

	.end:
		pop r8
		mov rsp, rbp
		pop rbp
		ret
