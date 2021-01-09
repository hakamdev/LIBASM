global _ft_strcpy
extern _ft_strlen

section .text
_ft_strcpy:
	push	rdi
	mov 	rdi, rsi
	call	_ft_strlen
	xor		rdx, rdx
	mov		rdx, rax
	pop		rdi
	mov		rax, rdi
	xor		r8, r8

cpy_loop:
	cmp		rdx, r8
	je		return
	mov		bl, BYTE [rsi + r8]
	mov		BYTE [rdi + r8], bl
	inc		r8
	jmp		cpy_loop

return:
	mov		BYTE [rdi + r8], 0
	ret
