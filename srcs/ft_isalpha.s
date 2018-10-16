section .text align=16
global _ft_isalpha

_ft_isalpha:
	push rbp
	mov rbp, rsp

	cmp rdi, 'Z'
	jg .is_lowerAlpha
	cmp rdi, 'A'
	jl .not_alpha
	jmp .ret_it_is_alpha

.is_lowerAlpha:
	cmp rdi, 'a'
	jl .not_alpha
	cmp rdi, 'z'
	jg .not_alpha
	jmp .ret_it_is_alpha

.not_alpha:
	xor rax, rax

	mov rsp, rbp
	pop rbp
	ret

.ret_it_is_alpha:
	mov rax, 1

	mov rsp, rbp
	pop rbp
	ret
