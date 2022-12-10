#ifndef CAT_CLASS
# define CAT_CLASS

#include "Animal.class.hpp"

# define C_CONSTRUCTOR			"Cat constructor called"
# define C_CONSTRUCTOR_PARAM	"Cat parameter constructor called"
# define C_CONSTRUCTOR_COPY		"Cat copy constructor called"
# define C_DESTRUCTOR			"Cat destructor called"

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const std::string &);
		Cat(const Cat &);

		void makeSound() const;
		Cat	&operator=(const Cat &);
};
std::ostream	&operator<<(std::ostream &, Cat &);

#endif
