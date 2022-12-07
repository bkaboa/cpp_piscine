NAME 		= 	phonebook

SRC 		= 	my_phone_book.cpp \
				Contact.Class.cpp \
				main.cpp

HEADER 		= 	Contact.Class.hpp \
				PhoneBook.Class.hpp

OBJS 		= 	$(SRC:.cpp=.o)

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

.PHONY 	: 	phonebook fclean all clean re
