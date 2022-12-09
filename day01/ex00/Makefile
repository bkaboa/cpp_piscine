NAME 	= 	BraiiiiiiinnnzzzZ

SRC 	= 	./main.cpp 			\
			./Zombie.cpp 		\
			./newZombie.cpp 	\
			./randomChump.cpp 	\

OBJS 	= 	$(SRC:.cpp=.o)

HEADER 	= 	./Zombie.hpp

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
GPP 		= 	c++

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

.PHONY 	: 	 fclean all clean re
