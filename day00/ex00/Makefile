SRC 	= 	megaphone.cpp
GPP 	= 	g++
NAME 	= 	megaphone
CFLAGS 	= 	-Wall -Wextra -Werror -std=c++98

all 	: 	$(NAME)

$(NAME) : 	Makefile $(SRC)
	$(GPP) $(CFLAGS) -o $@ $(SRC)

clean 	:

fclean 	: clean
	@rm $(NAME) || true

re 		: fclean all

.PHONY 	: all fclean re clean
