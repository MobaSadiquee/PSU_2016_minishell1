##
## Makefile for Makefile in /home/sadiqu-m/delivery/Systeme_unix/PSU_2016_minishell1
## 
## Made by Sadiqu-m
## Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
## 
## Started on  Thu Jan 12 16:35:34 2017 Sadiqu-m
## Last update Sun Jan 22 18:03:07 2017 Sadiqu-m
##

NAME            = mysh

SRC             = ./src/my_basic_fonc.c \
		  ./src/my_shell.c \
		  ./src/my_fonc_shell.c \
		  ./src/my_basic_nbr.c \
		  ./src/my_str_to_wordtab.c \
		  ./src/main.c

CC              = gcc

RM              = rm -rf

OBJ             = $(SRC:.c=.o)

CFLAGS          = -I./include -I. 

LFLAGS          =

all:
	@make --no-print-directory $(NAME)

$(NAME):        $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:     fclean all
