NAME 	= 	kombat

SRC 	= 	./main.cpp 		\
			./HumanA.cpp 	\
			./HumanB.cpp 	\
			./Weapon.cpp

HEADER 	= 	./HumanA.hpp 	\
			./HumanB.hpp 	\
			./Weapon.hpp

OBJS 	= 	$(SRC:.cpp=.o)

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98 -fsanitize=address
GPP 		= 	g++

all: $(NAME)

%.o:%.cpp Makefile $(HEADER)
	$(GPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(GPP) $(CPPFLAGS) -o $@ $^

clean 	:
	rm $(OBJS)

fclean 	: 	clean
	rm $(NAME)

re 		: 	fclean all

.PHONY 	: 	phonebook fclean all clean re
