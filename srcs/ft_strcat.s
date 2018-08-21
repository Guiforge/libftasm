section .text align=16
global _ft_strcat
extern _ft_strlen

_ft_strcat:
	push rbp
	mov rbp, rsp

	; save src
	mov r8, rdi

	; strlen src
	push rdi
	call _ft_strlen
	pop rdi
	add rdi, rax

	; add rdi, rax

	.copy:
		cmp [rsi], byte 0
		je .end
		mov  r9, [rsi]
		mov  [rdi], r9
		inc rdi
		inc rsi
	jmp .copy

.end:
	mov rax, r8
	mov rsp, rbp
	pop rbp
	ret