all: c
	@nasm -fmacho64 ft_strdup.asm
	@nasm -fmacho64 ft_strlen.asm
	@nasm -fmacho64 ft_strcpy.asm
	@nasm -fmacho64 ft_strcmp.asm
	@nasm -fmacho64 ft_write.asm
	@nasm -fmacho64 ft_read.asm

b:
	@gcc main.c ft_strdup.o ft_strlen.o ft_strcpy.o ft_strcmp.o ft_write.o ft_read.o

r:
	@./a.out

c:
	@rm -rf *.o a.out