#ifndef DOG_CLASS
# define DOG_CLASS

#include "Animal.class.hpp"

# define C_CONSTRUCTOR			"Dog constructor called"
# define C_CONSTRUCTOR_PARAM	"Dog parameter constructor called"
# define C_CONSTRUCTOR_COPY		"Dog copy constructor called"
# define C_DESTRUCTOR			"Dog destructor called"

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const std::string &);
		Dog(const Dog &);

		void makeSound() const;
		Dog	&operator=(const Dog &);
};
std::ostream	&operator<<(std::ostream &, Dog &);

#endif
