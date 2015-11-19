CC := gcc
CXX := g++

OBJS := matplotpp.o gl2ps.o

NAME := libmatplotpp.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
