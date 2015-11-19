##
## Makefile for makefile in /home/casier_s/os-home/minishell
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Fri Dec 14 15:10:45 2012 sofian casier
## Last update Mon Jan  2 10:09:04 2012 sofian casier
##

SRC=            main.c \
		minishell.c \
		base_fonc.c \
		base_fonc2.c \
		wait_exec.c \
		base_fonc3.c \
		base_fonc4.c \
		epur_str.c \
		mem_opt.c \
		pipe.c \
		point.c \
		termcap.c \
		base_fonc5.c \

OBJS=           $(SRC:.c=.o)

NAME=           mysh

CC=             gcc -g -lncurses

RM=             rm -f

$(NAME):        $(OBJS)
		cc -o $(NAME) $(OBJS)  -lncurses

all:            $(NAME)


clean:
		$(RM)    $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean all