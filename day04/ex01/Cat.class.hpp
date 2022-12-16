#ifndef CAT_CLASS
# define CAT_CLASS

# include "Animal.class.hpp"
# include "Brain.class.hpp"

# define C_CONSTRUCTOR			"Cat constructor called"
# define C_CONSTRUCTOR_PARAM	"Cat parameter constructor called"
# define C_CONSTRUCTOR_COPY		"Cat copy constructor called"
# define C_DESTRUCTOR			"Cat destructor called"

class Cat: public Animal
{
	private:
		Brain	*brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat &);

		void	printBrain(void) const;
		void	set10BrainLine(const std::string &) const;
		void makeSound() const;
		Cat	&operator=(const Cat &);
};
std::ostream	&operator<<(std::ostream &, Cat &);

#endif
