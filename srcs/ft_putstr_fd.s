%define STDOUT				1
%define WRITE				4
%define MACH_SYSCALL(x)		0x2000000 | x

section .text align=16
global _ft_putstr_fd
extern _ft_strlen

_ft_putstr_fd:
	push rbp
	mov rbp, rsp
	sub rsp, 16

	push r8
	push r9
	push rax

	cmp rdi, byte 0
	je .end

.print_param:
	mov r8, rdi

	call _ft_strlen
	mov r9, rax

	mov rax, MACH_SYSCALL(WRITE)
	mov rdi, rsi
	mov rsi, r8
	mov rdx, r9
	syscall

.end:
	pop r8
	pop r9
	pop rax
	mov rsp, rbp
	pop rbp
	ret

