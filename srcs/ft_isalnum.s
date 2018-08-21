section .text align=16

global _ft_isalnum
extern _ft_isalpha
extern _ft_isdigit

_ft_isalnum:
    push rbp
    mov rbp, rsp

    xor rax, rax

.is_alpha:
    call _ft_isalpha
    cmp rax, 0
    je .is_digit
    mov rax, 1
    jmp .end

.is_digit:
    call _ft_isdigit
    cmp rax, 0
    je .end
    mov rax, 1
    jmp .end

.end:
    mov rsp, rbp
    pop rbp
    ret
