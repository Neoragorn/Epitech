##
## Makefile for Makefile in /home/amoure_a//igraph/ray_tracer
## 
## Made by alix amoureux
## Login   <amoure_a@epitech.net>
## 
## Started on  Tue Feb  5 09:02:27 2013 alix amoureux
## Last update Tue Apr  9 16:01:00 2013 sofian casier
##

CC      = gcc

RM      = rm -f

NAME    = 110borwein

SRCS    = main.c\

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)  -L /usr/X11/lib -lm

clean:
	 $(RM) $(OBJS)

fclean:
	$(RM) $(OBJS)
	$(RM) $(NAME)

re: fclean all clean

.PHONY: all clean fclean re