section .text align=16
global _ft_isdigit

_ft_isdigit:
	push rbp
	mov rbp, rsp

	cmp rdi, '0'
	jl .not_digit
	cmp rdi, '9'
	jg .not_digit
	mov rax, 1

	mov rsp, rbp
	pop rbp
	ret

.not_digit:
	xor rax, rax

	mov rsp, rbp
	pop rbp
	ret