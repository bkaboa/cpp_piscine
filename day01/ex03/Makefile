NAME 	= 	kombat

SRC 	= 	./main.cpp 		\
			./HumanA.cpp 	\
			./HumanB.cpp 	\
			./Weapon.cpp

HEADER 	= 	./HumanA.hpp 	\
			./HumanB.hpp 	\
			./Weapon.hpp

OBJS 	= 	$(SRC:.cpp=.o)

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98 -fsanitize=address -g3
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

.PHONY 	: 	fclean all clean re
