NAME 		= 	span

SRC 		= 	main.cpp 	\
				./span.cpp

HEADER 		= 	./Span.hpp

OBJS 		= 	$(SRC:.cpp=.o)

CPPFLAGS 	= 	-Wall -Wextra -Werror -std=c++98 #-fsanitize=address -g3
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

.PHONY 	: 	fclean all clean re
