##
## Makefile for make in /home/casier_s//minitalk
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Mon Mar 18 22:23:24 2013 sofian casier
## Last update Sun Mar 24 18:32:53 2013 sofian casier
##

NAME_ONE=	./client/client

NAME_TWO=	./server/server

CC=		cc -g

RM=		rm -f

SRC_O=		./client/main.c \
		./client/base_fonc.c \
		./client/base_fonc2.c \
		./client/base_fonc3.c \

SRC_T=		./server/main.c \
		./server/base_fonc.c \
		./server/base_fonc2.c \
		./server/base_fonc3.c \

OBJ_O=		$(SRC_O:.c=.o)

OBJ_T=		$(SRC_T:.c=.o)

CFLAGS=		-g

all:		$(NAME_ONE) $(NAME_TWO)

$(NAME_ONE):	$(OBJ_O)
		$(CC) $(OBJ_O) -o $(NAME_ONE)

$(NAME_TWO):	$(OBJ_T)
		$(CC) $(OBJ_T) -o $(NAME_TWO)

clean:
		$(RM) $(OBJ_O) $(OBJ_T)

fclean:		clean
		$(RM) $(NAME_ONE) $(NAME_TWO)

re:		fclean all