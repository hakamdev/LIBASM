global _ft_strcmp
extern _ft_strlen

section .text
_ft_strcmp:
	call	_ft_strlen
	xor		r8, r8
	xor		rdx, rdx
	mov		rdx, rax

cmp_loop:
	cmp		rdx, r8
	je		compare
	mov		cl, BYTE [rsi]
	cmp		[rdi], cl
	jne		compare
	inc		rdi
	inc		rsi
	inc		r8
	jmp		cmp_loop

compare:
	movzx	rdi, BYTE [rdi]
	movzx	rsi, BYTE [rsi]
	mov		rax, rdi
	sub		rax, rsi
	ret