NAME 	= 	BraiiiiiiinnnzzzZ

SRC 	= 	./main.cpp 			

OBJS 	= 	$(SRC:.cpp=.o)

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
GPP 		= 	g++

all: $(NAME)

%.o:%.cpp Makefile
	$(GPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(GPP) -o $@ $^

clean 	:
	@rm $(OBJS) || true

fclean 	: 	clean
	@rm $(NAME) || true

re 		: 	fclean all

.PHONY 	: 	fclean all clean re
