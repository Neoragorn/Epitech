##
## Makefile for make in /home/casier_s//colle3
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Tue May  7 09:35:43 2013 sofian casier
## Last update Tue May  7 09:41:57 2013 sofian casier
##

SRC=            main.c \
		basefonc.c \

OBJS=           $(SRC:.c=.o)

NAME=           carre

CC=             gcc -g -Wall -Wextra

LINK=		-L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11 -lm

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