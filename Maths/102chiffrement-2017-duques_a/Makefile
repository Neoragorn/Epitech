##
## Makefile for Makefile in /home/duques_a/102chiffrement-2017-duques_a
## 
## Made by pierre duquesnoy
## Login   <duques_a@epitech.net>
## 
## Started on  Tue Nov 27 13:17:01 2012 pierre duquesnoy
## Last update Wed Nov 28 13:32:24 2012 pierre duquesnoy
##

SRC=	102chiffrement.c \
	usiv_func.c \
	alph_func.c

NAME=	102chiffrement

OBJ=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re:	fclean all