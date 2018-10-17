section .text align=16
global _ft_strcat
extern _ft_strlen
extern _ft_strcpy

_ft_strcat:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	push rdi

	call _ft_strlen

	add rdi, rax 
	call _ft_strcpy

.end:
	pop rdi
	mov rax, rdi
	mov rsp, rbp
	pop rbp
	ret
