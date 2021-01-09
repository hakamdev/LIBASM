global _ft_strlen

section .text
_ft_strlen:
	xor rax, rax
	mov eax, -1
len_loop:
	inc eax
	cmp BYTE [rdi + rax], 0
	jne len_loop
	ret