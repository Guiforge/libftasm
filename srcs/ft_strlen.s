section .text align=16
	global _ft_strlen

_ft_strlen:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	push rdi
	cld
	mov rax, 0
	mov rcx, -1
	repne scasb
	add rcx, 2
	neg rcx
	pop rdi

.end: 
	mov rax, rcx
	mov rsp, rbp
	pop rbp
	ret
