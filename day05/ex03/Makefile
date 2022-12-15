NAME 		= 	Bureaucrat

SRC 		= 	./Bureaucrat.cpp 				\
				./Form.cpp 						\
				./PresidentialPardonForm.cpp 	\
				./RobotomyRequestForm.cpp 		\
				./ShrubberyCreationForm.cpp 	\
				./Intern.cpp 					\
				main.cpp

HEADER 		= 	./Bureaucrat.hpp 				\
				./PresidentialPardonForm.hpp 	\
				./RobotomyRequestForm.hpp 		\
				./ShrubberyCreationForm.hpp 	\
				./Intern.hpp 					\
				./Form.hpp

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

.PHONY 	: 	fclean all clean re
