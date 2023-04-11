NAME	:= RPN

HEADER	:=	RPN.hpp

SRC 	:= main.cpp	\
		   RPN.cpp

OBJ 	:= $(SRC:.cpp=.o)

FLAGS	:=	-Wall -Wextra -Werror -std=c++98

GPP		:=	c++

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	$(GPP) $(FLAGS) -o $@ $^

%.o:%.cpp Makefile $(HEADER)
	$(GPP) -o $@ -c $<

clean	:
	@rm $(OBJ) || true

fclean	: clean
	@rm $(NAME) || true

re		: fclean all

.PHONY	: fclean all re clean
