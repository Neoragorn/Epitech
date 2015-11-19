##
## Makefile for makefile in /home/casier_s/os-home/minishell
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Fri Dec 14 15:10:45 2012 sofian casier
## Last update Tue Jan 15 23:33:14 2013 clement liagre
##

SRC=            main.c \
		my_functions.c \
		bissection.c \
		newton.c \
		secante.c

OBJS=           $(SRC:.c=.o)

NAME=           105tore

CC=             gcc -g

LINK=		-lm

RM=             rm -f

all:            $(NAME)

$(NAME):        $(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LINK)

clean:
		$(RM)    $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean all