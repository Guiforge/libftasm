section .text align=16
global _ft_isascii

_ft_isascii:
    push rbp
    mov rbp, rsp

    cmp rdi, 0
    jl .not_ascii
    cmp rdi, 127
    jg .not_ascii
    mov rax, 1

	mov rsp, rbp
	pop rbp
	ret

.not_ascii:
    xor rax, rax

	mov rsp, rbp
	pop rbp
	ret