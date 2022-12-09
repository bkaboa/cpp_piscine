NAME 		= 	Harl

SRC 		= 	./Harl.cpp 	\
				./main.cpp

OBJS 		= 	$(SRC:.cpp=.o)

HEADER 		= 	./Harl.hpp

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98

GPP 		= 	g++

all: 	$(NAME)

%.o:%.cpp 	Makefile $(HEADER)
	$(GPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(GPP) $(CPPFLAGS) -o $@ $^

clean:
	@rm $(OBJS) || true

fclean: clean
	@rm $(NAME) || true

re: fclean all

.PHONY 	: 	fclean all clean re
