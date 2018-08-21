section .text align=16
global _ft_toupper

_ft_toupper:
    push rbp
    mov rbp, rsp

    cmp rdi, 'a'
    jl .not_lower
    cmp rdi, 'z'
    jg .not_lower
    sub rdi, 32
    mov rax, rdi

	mov rsp, rbp
	pop rbp
	ret

.not_lower:
    mov rax, rdi

    mov rsp, rbp
	pop rbp
	ret