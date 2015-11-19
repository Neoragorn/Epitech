CXX := g++

CXXFLAGS := -Imatplotpp -Iinclude -Wall -g
LDFLAGS := -Lmatplotpp -lmatplotpp -lglut -lGLU -lGL

SRCS := src/main.cpp src/Equation.cpp src/Grapher.cpp src/Benchmark.cpp
OBJS := $(SRCS:.cpp=.o)

NAME := 107transfert

all: $(NAME)

$(NAME): matplotpp/libmatplotpp.a $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

matplotpp/libmatplotpp.a:
	make -C matplotpp re

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
