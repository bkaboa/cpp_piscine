NAME 		= 	phonebook

SRC 		= 	my_phone_book.cpp \
				Contact.Class.cpp \
				main.cpp

HEADER 		= 	Contact.Class.hpp \
				PhoneBook.Class.hpp

OBJS 		= 	$(SRC:.cpp=.o)

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

.PHONY 	: 	phonebook fclean all clean re
