section .text align=16
	global _ft_strlen

_ft_strlen:
    push rbp
    mov rbp, rsp
	xor   rcx, rcx

.next:
	cmp [rdi], byte 0
	je .end
	inc rdi
	inc rcx
	jmp .next

.end: 
	mov rax, rcx

	mov rsp, rbp
	pop rbp
	ret