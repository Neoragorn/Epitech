##
## Makefile for makefile in /home/casier_s/os-home/tpmyls
## 
## Made by sofian casier
## Login   <casier_s@epitech.net>
## 
## Started on  Thu Nov 29 19:52:02 2012 sofian casier
## Last update Sat Dec  1 23:45:51 2012 sofian casier
##

SRC=            my_type.c \
                right_type.c \
                base_fonc.c \
		info_time.c \
		read_info.c \
		my_main.c \
		display.c \

OBJS=           $(SRC:.c=.o)

NAME=           my_ls

CC=             gcc -g -Wall

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