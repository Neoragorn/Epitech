##
## Makefile for makefile in /home/casier_s/os-home/minishell
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Fri Dec 14 15:10:45 2012 sofian casier
## Last update Tue Apr 23 10:43:07 2013 sofian casier
##

SRC=            main.c \
		write.c \
		addition.c \
		soustraction.c \
		division.c \

OBJS=           $(SRC:.c=.o)

NAME=           pi

CC=             gcc -g -lncurses

RM=             rm -f

$(NAME):        $(OBJS)
		cc -o $(NAME) $(OBJS)

all:            $(NAME)


clean:
		$(RM)    $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean all