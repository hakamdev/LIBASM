global _ft_read
extern ___error

section .text
_ft_read:
	mov		rax, 0x2000003
	syscall
	jc		_error
	ret

_error:
	push	rax,
	call	___error
	pop		QWORD [rax]
	mov		rax, -1
	ret

