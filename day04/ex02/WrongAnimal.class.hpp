#ifndef WRONGANIMAL_CLASS
# define WRONGANIMAL_CLASS

# include "Animal.class.hpp"

# define WA_CONSTRUCTOR				"WrongAnimal constructor called"
# define WA_CONSTRUCTOR_PARAM		"WrongAnimal parameter constructor called"
# define WA_CONSTRUCTOR_COPY		"WrongAnimal copy constructor called"
# define WA_DESTRUCTOR				"WrongAnimal destructor called"

class	WrongAnimal
{
	protected:
		std::string _type;
	
	public:
		WrongAnimal();
		WrongAnimal(const std::string &);
		WrongAnimal(const WrongAnimal&);
		~WrongAnimal();

		WrongAnimal	&operator=(const WrongAnimal&);
		void	makesound() const;
		const std::string	&getType(void) const;
		void	setType(const std::string&);
};

#endif
