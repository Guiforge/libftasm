section .text align=16
global _ft_strdup
extern _ft_strlen
extern _ft_memalloc
extern _ft_strcpy

_ft_strdup:
	push rbp
	mov rbp,rsp
	sub rsp, 0x20

	mov QWORD [rbp - 0x10], rdi ; save rdi
	mov QWORD [rbp - 0x8], 0x0 ; set return

	; cmp QWORD [rbp - 0x10], 0x0
	; je .end

	call _ft_strlen
	mov rdi, rax
	call _ft_memalloc
	cmp rax, 0x0
	je .end
	
	mov rdi, rax
	mov rsi, QWORD [rsp + 0x10]
	call _ft_strcpy
	mov QWORD [rbp - 0x8], rax
	.end:
		mov rax, QWORD [rbp - 0x8]
		add rsp, 0x20
		pop rbp
		ret
