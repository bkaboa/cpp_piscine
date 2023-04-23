NAME	:=  PmergeMe

HEADER	:=	PmergeMe.hpp

SRC 	:= main.cpp	\
		   PmergeMe.cpp

OBJ 	:= $(SRC:.cpp=.o)

FLAGS	:=	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3

GPP		:=	c++

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(GPP) $(FLAGS) -o $@ $^

%.o:%.cpp Makefile $(HEADER)
	$(GPP) $(FLAGS) -o $@ -c $<

clean	:
	@rm $(OBJ) || true

fclean	: clean
	@rm $(NAME) || true

re		: fclean all

.PHONY	: fclean all re clean

