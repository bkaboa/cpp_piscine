NAME 	= 	BraiiiiiiinnnzzzZ

SRC 	= 	./main.cpp 			\
			./Zombie.cpp 		\
			./zombieHorde.cpp

OBJS 	= 	$(SRC:.cpp=.o)

HEADER 	= 	./Zombie.hpp

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
GPP 		= 	g++

all: $(NAME)

%.o:%.cpp Makefile $(HEADER)
	$(GPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(GPP) -o $@ $^

clean 	:
	rm $(OBJS)

fclean 	: 	clean
	rm $(NAME)

re 		: 	fclean all

.PHONY 	: 	phonebook fclean all clean re
