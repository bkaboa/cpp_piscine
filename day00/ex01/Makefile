SRC 		= 	Contact.Class.cpp my_phone_book.cpp
CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98
GPP 		= 	g++
HEADER 		= 	Contact.Class.hpp
NAME 		= 	phonebook
OBJS 		= 	$(SRC:./c=.o)

all 	: 	$(NAME)

%.o 	: 	%.c $(HEADER) Makefile
	$(GPP) $(CPPFLAGS) -I -c $< -o $@

$(NAME) : 	$(OBJS)
	$(GPP) $(CPPFLAGS) -o $@ $^

clean 	:
	rm $(OBJS)

fclean 	: 	clean
	rm $(NAME)

re 		: 	fclean all

.PHONY 	: 	phonebook fclean all clean re
