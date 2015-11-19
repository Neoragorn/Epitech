##
## Makefile for makefile in /home/casier_s/os-home/minishell
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Fri Dec 14 15:10:45 2012 sofian casier
## Last update Sun Jan 20 22:32:22 2013 sofian casier
##

SRC=            main.c \
		basefonc.c \
		cursor.c \
		chained_list.c \
		change_list.c \

OBJS=           $(SRC:.c=.o)

NAME=           my_select

CC=             gcc -g

LINK=		-lm -lncurses -Wall

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