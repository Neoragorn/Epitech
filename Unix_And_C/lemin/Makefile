##
## Makefile for make in /home/casier_s//lemin
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Wed Apr  3 15:45:33 2013 sofian casier
## Last update Thu Apr 25 18:12:17 2013 sofian casier
##

SRC=            lemin.c \
		write.c \
		epur_str.c \
		get_nbr.c \
		check.c \
		check_ant_end_start.c \
		check_room.c \
		check_link.c \
		keep.c \
		table_data.c \
		mem_cmp.c \

OBJS=           $(SRC:.c=.o)

NAME=           lem_in

CC=             gcc  -g -lncurses

CFLAGS=		-W -Wextra -Wall

RM=             rm -f

$(NAME):        $(OBJS)
		cc -o $(NAME) $(OBJS)

all:            $(NAME)

clean:
		$(RM)    $(OBJS)

fclean:         clean
		$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean all