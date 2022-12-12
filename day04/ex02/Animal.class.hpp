#ifndef ANIMAL_CLASS
# define ANIMAL_CLASS

# include <string>
# include <iostream>

# define A_CONSTRUCTOR			"Animal constructor called"
# define A_CONSTRUCTOR_PARAM	"Animal parameter constructor called"
# define A_CONSTRUCTOR_COPY		"Animal copy constructor called"
# define A_DESTRUCTOR			"Animal destructor called"


class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal &);
		virtual ~Animal();
		Animal(const std::string &type);

		Animal	&operator=(const Animal &);

		virtual void	makeSound() const = 0;
		const std::string	&getType() const;
		void	setType(const std::string &);
};

std::ostream	&operator<<(std::ostream &, const Animal &);

#endif
