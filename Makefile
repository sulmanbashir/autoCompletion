##
## Makefile for Makefile in /home/bashir_s/rendu/PSU_2014_myftp
## 
## Made by sulman bashir
## Login   <bashir_s@epitech.net>
## 
## Started on  Sun Mar 22 21:08:20 2015 sulman bashir
## Last update Fri Jul 17 14:02:32 2015 sulman bashir
##

CC	= gcc

RM	= rm -f

SRC	= autoCompletion.c \
	save.c \
	cut.c \
	init.c \
	program.c \
	list.c \
	prompt.c \

OBJ	= $(SRC:.c=.o)

NAME	= autoCompletion

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(SRC)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
