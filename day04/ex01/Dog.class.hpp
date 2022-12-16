#ifndef DOG_CLASS
# define DOG_CLASS

#include "Animal.class.hpp"
#include "Brain.class.hpp"

# define D_CONSTRUCTOR			"Dog constructor called"
# define D_CONSTRUCTOR_PARAM	"Dog parameter constructor called"
# define D_CONSTRUCTOR_COPY		"Dog copy constructor called"
# define D_DESTRUCTOR			"Dog destructor called"

class Dog: public Animal
{
	private:
		Brain	*brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog &);

		void	printBrain(void) const;
		void	set10BrainLine(const std::string &) const;
		void makeSound() const;
		Dog	&operator=(const Dog &);
};
std::ostream	&operator<<(std::ostream &, Dog &);

#endif
