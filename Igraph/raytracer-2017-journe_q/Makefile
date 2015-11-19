##
## Makefile for makefile in /home/journe_q//math/105
## 
## Made by quentin journet
## Login   <journe_q@epitech.net>
## 
## Started on  Mon Jan 14 13:44:19 2013 quentin journet
## Last update Sun Jun  9 15:18:09 2013 sofian casier
##

NAME=		rt

COMP=		gcc -o

RM=		rm -f

SRC=		main.c					\
		./get_next_line/get_next_line.c		\
		./get_next_line/base_funct.c		\
		./multi_obj/list.c			\
		./multi_obj/malloc.c			\
		./get_next_line/base_func_for_get.c	\
		./manage_error/my_error1.c		\
		./manage_error/check_number.c		\
		./manage_error/my_error3.c		\
		./base_fonc/usualfonction.c		\
		./calc/sphere.c				\
		./calc/plan.c				\
		./calc/cylindre.c			\
		./calc/cone.c				\
		./calc/findcolor.c			\
		./calc/lux1.c				\
		./calc/shadow/shadow.c			\
		./calc/shadow/shadow_para.c		\
		./calc/shadow/shadow_cyl.c		\
		./calc/shadow/shadow_cone.c		\
		./calc/shadow/shadow_plan.c		\
		./calc/shadow/shadow_sph.c		\
		./manage_error/my_error2.c		\
		./calc/mppti.c				\
		./calc/rotate/rotate_eye.c		\
		./calc/eyevector.c			\
		./calc/paraboloid.c			\
		./base_fonc/my_str_to_word_tab.c	\
		./bonus/thread.c			\
		./bonus/thread2.c			\
		./bonus/thread3.c			\
		./calc/checker.c			\
		./bonus/lenght.c			\
		./bmpfile/bmpfile.c			\
		./bonus/create_bmp.c			\

OBJ=		$(SRC:.c=.o)

LINK=		-L/usr/lib64 -lmlx_$$HOSTTYPE -L/usr/lib64/X11 -lXext -lX11 -lm -I . -pthread

CFLAGS=		-g

all:		$(NAME)

$(NAME):	$(OBJ)
		$(COMP) $(NAME) $(OBJ) $(LINK)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all