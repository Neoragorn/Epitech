##
## Makefile for makefile in /home/casier_s/os-home/103architecte-2017-casier_s
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Mon Dec 10 16:06:54 2012 sofian casier
## Last update Thu Dec 13 15:22:01 2012 sofian casier
##

CC = gcc 

CFLAGS += -g

SRCS=   archi.c \
	base_fonc.c \
	rotation.c \
	homotethie.c \
	symetry.c

NAME=   103architecte

OBJS=   $(SRCS:.c=.o)

all:            $(NAME)

$(NAME):        $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lm

clean:
	rm -f $(OBJS)

fclean:         clean
	rm -f $(NAME)

re:     fclean all