NAME 	= 	sedForNoob

SRC 	= 	./main.cpp 			\
			./application.cpp 	\
			./check.cpp 		\

HEADER 	= 	./application.hpp 	\
			./check.hpp 		\

OBJS 	= 	$(SRC:.cpp=.o)

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
