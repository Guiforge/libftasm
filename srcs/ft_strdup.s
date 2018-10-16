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
	push r9

	mov r8, rdi
	call _ft_strlen
	mov r9, rax
	inc r9


	mov rdi, r9
	push r8
	call _ft_memalloc
	pop r8
	mov r9, rax
	cmp rax, 0
	je .end

	mov rdi, r9
	mov rsi, r8
	call _ft_strcpy

	.end:
		pop r8
		pop r9
		mov rsp, rbp
		pop rbp
		ret
