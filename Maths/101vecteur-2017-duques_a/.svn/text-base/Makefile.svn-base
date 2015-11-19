##
## Makefile for Makefile in /home/duques_a/101vecteur-2017-duques_a
## 
## Made by pierre duquesnoy
## Login   <duques_a@epitech.net>
## 
## Started on  Sat Nov 10 13:44:13 2012 pierre duquesnoy
## Last update Tue Nov 13 14:01:49 2012 pierre duquesnoy
##

SRC=	calc_vecteur.c \
	rnd_vecteur.c \
	usiv_func.c \
	my_getnbr.c \
	my_strlen.c \

NAME=	101vecteur

OBJ=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)

re: fclean all