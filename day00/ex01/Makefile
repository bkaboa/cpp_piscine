NAME 		= 	phonebook

SRC 		= 	my_phone_book.cpp Contact.Class.cpp
HEADER 		= 	Contact.Class.hpp

OBJS 		= 	$(SRC:.cpp=.o))

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
GPP 		= 	g++

all: $(NAME)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(GPP) -o $(NAME) $(OBJS)

clean 	:
	rm $(OBJS)

fclean 	: 	clean
	rm $(NAME)

re 		: 	fclean all

.PHONY 	: 	phonebook fclean all clean re
