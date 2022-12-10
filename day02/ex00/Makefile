NAME 	= 	firstCanon

SRC 	= 	./main.cpp 			\
			./Fixed.cpp

HEADER 	= 	./Fixed.hpp

OBJS 	= 	$(SRC:.cpp=.o)

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
GPP 		= 	g++

all: $(NAME)

%.o:%.cpp Makefile $(HEADER)
	$(GPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(GPP) -o $@ $^

clean 	:
	@rm $(OBJS) || true

fclean 	: 	clean
	@rm $(NAME) || true

re 		: 	fclean all

.PHONY 	: 	fclean all clean re
