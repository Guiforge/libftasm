section .text align=16
global _ft_isprint

_ft_isprint:
	push rbp
	mov rbp, rsp

	cmp rdi, 32
	jl .not_print
	cmp rdi, 126
	jg .not_print
	mov rax, 1

	mov rsp, rbp
	pop rbp
	ret

.not_print:
	xor rax, rax

	mov rsp, rbp
	pop rbp
	ret