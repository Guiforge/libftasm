%define STDOUT				1
%define WRITE				4
%define MACH_SYSCALL(x)		0x2000000 | x

section .text align=16
global _ft_putstr
extern _ft_putstr_fd

_ft_putstr:
	push rbp
	mov rbp, rsp
	mov rsi, STDOUT
	call _ft_putstr_fd

.end:
	mov rsp, rbp
	pop rbp
	ret

