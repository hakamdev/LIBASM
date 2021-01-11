all: clean
	@nasm -fmacho64 ft_strdup.asm
	@nasm -fmacho64 ft_strlen.asm
	@nasm -fmacho64 ft_strcpy.asm
	@nasm -fmacho64 ft_strcmp.asm

build:
	@gcc main.c ft_strdup.o ft_strlen.o ft_strcpy.o ft_strcmp.o

run:
	@./a.out

clean:
	@rm -rf *.o a.out