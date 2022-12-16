#ifndef DOG_CLASS
# define DOG_CLASS

#include "Animal.class.hpp"

# define D_CONSTRUCTOR			"Dog constructor called"
# define D_CONSTRUCTOR_PARAM	"Dog parameter constructor called"
# define D_CONSTRUCTOR_COPY		"Dog copy constructor called"
# define D_DESTRUCTOR			"Dog destructor called"

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &);

		void makeSound() const;
		Dog	&operator=(const Dog &);
};
std::ostream	&operator<<(std::ostream &, Dog &);

#endif
