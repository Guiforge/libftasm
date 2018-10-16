section .text align=16
global _ft_tolower

_ft_tolower:
	push rbp
	mov rbp, rsp

	cmp rdi, 'A'
	jl .not_upper
	cmp rdi, 'Z'
	jg .not_upper
	add rdi, 32
	mov rax, rdi

	mov rsp, rbp
	pop rbp
	ret

.not_upper:
	mov rax, rdi

	mov rsp, rbp
	pop rbp
	ret