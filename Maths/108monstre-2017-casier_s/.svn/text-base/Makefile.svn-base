##
## Makefile for Makefile in /home/amoure_a//igraph/ray_tracer
## 
## Made by alix amoureux
## Login   <amoure_a@epitech.net>
## 
## Started on  Tue Feb  5 09:02:27 2013 alix amoureux
## Last update Mon Mar 18 17:11:46 2013 alix amoureux
##

CC      = gcc -ggdb3

RM      = rm -f

NAME    = 108monstre

SRCS    = main.c\

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  -L /usr/X11/lib -lmlx -lXext -lX11 -lm -I /usr/X11/include/

clean:
	 $(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all clean

.PHONY: all clean fclean re