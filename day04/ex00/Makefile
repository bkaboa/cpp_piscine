NAME 		= 	Animal

SRC 		= 	./Animal.class.cpp 	\
				./Cat.class.cpp 	\
				./Dog.class.cpp 	\
				main.cpp

HEADER 		= 	./Animal.class.hpp 	\
				./Cat.class.hpp 	\
				./Dog.class.hpp

OBJS 		= 	$(SRC:.cpp=.o)

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
GPP 		= 	g++

all: $(NAME)

%.o:%.cpp Makefile $(HEADER)
	$(GPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(GPP) $(CPPFLAGS) -o $@ $^

clean 	:
	@rm $(OBJS) || true

fclean 	: 	clean
	@rm $(NAME) || true

re 		: 	fclean all

.PHONY 	: 	phonebook fclean all clean re
