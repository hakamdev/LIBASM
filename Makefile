# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehakam <ehakam@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/12 11:42:43 by ehakam            #+#    #+#              #
#    Updated: 2021/01/12 12:14:46 by ehakam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile -*-

SRC  =	ft_strdup.s \
		ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s
NAME = libasm.a
NASM = nasm -fmacho64
CC   = gcc
LIBCC= ar rc
FLGS = -Wall -Wextra -Werror
OBJ =	ft_strdup.o \
		ft_strlen.o \
		ft_strcpy.o \
		ft_strcmp.o \
		ft_write.o \
		ft_read.o

all: $(NAME)

$(NAME): $(OBJ)
	@$(LIBCC) $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJ): $(SRC)
	@$(NASM) ft_strdup.s -o ft_strdup.o
	@$(NASM) ft_strlen.s -o ft_strlen.o
	@$(NASM) ft_strcpy.s -o ft_strcpy.o
	@$(NASM) ft_strcmp.s -o ft_strcmp.o
	@$(NASM) ft_write.s -o ft_write.o
	@$(NASM) ft_read.s -o ft_read.o

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) a.out

re: fclean all

test: a.out
	@./a.out

a.out: $(NAME)
	@$(CC) $(FLGS) main.c $(NAME)
