##
## Makefile for makefile in /home/casier_s/os-home/minishell
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Fri Dec 14 15:10:45 2012 sofian casier
## Last update Mon Jun  3 16:43:54 2013 sofian casier
##

SRC=            main.c \
		basefonc.c \
		rotation.c \
		display_pixel.c \
		light.c \
		color.c \
		brilliance.c \
		cyl.c \
		light2.c \
		create.c \
		rotationcyl.c \
		paral.c \

OBJS=           $(SRC:.c=.o)

NAME=           rtv1

CC=             gcc -g

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