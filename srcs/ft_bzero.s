section .text align=16
	global _ft_bzero

_ft_bzero:
	push rbp
	mov rbp, rsp
	
	xor al, al ; value stosb
	cld ; clear direction flag
	mov rcx, rsi ; len of string
	rep stosb ; repeat set byte from al

	mov rsp, rbp
	pop rbp
	ret
