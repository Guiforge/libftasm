%define STDOUT              1
%define WRITE               4
%define MACH_SYSCALL(x)     0x2000000 | x
%define EOF					-1

section .data
	newline db 10
	nul db "(null)"

section .text align=16
global _ft_puts
extern _ft_strlen

_ft_puts:
	push rbp
	mov rbp, rsp

	cmp rdi, byte 0
	je .nul_ret

.print_param:
	mov r8, rdi

	call _ft_strlen
	mov r9, rax

	mov rax, MACH_SYSCALL(WRITE)
	mov rdi, STDOUT
	mov rsi, r8
	mov rdx, r9
	syscall
	jc .end_fail

.print_newline:
	mov rax, MACH_SYSCALL(WRITE)
	mov rdi, STDOUT
	lea rsi, [rel newline]
	mov rdx, 1
	syscall
	jc .end_fail

	mov rax, 10
	jmp .end

.end:
	mov rsp, rbp
	pop rbp
	ret

.end_fail:
	mov rax, EOF
	jmp .end


.nul_ret:
	mov rax, MACH_SYSCALL(WRITE)
	mov rdi, STDOUT
	lea rsi, [rel nul]
	mov rdx, 6
	syscall
	jc .end_fail
	jmp .print_newline