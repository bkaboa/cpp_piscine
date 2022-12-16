#ifndef WRONGCAT_CLASS
# define WRONGCAT_CLASS

# include "WrongAnimal.class.hpp"

# define WC_CONSTRUCTOR				"WrongCat constructor called"
# define WC_CONSTRUCTOR_PARAM		"WrongCat parameter constructor called"
# define WC_CONSTRUCTOR_COPY		"WrongCat copy constructor called"
# define WC_DESTRUCTOR				"WrongCat destructor called"

class	WrongCat:public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string &);
		WrongCat(const WrongCat &);
		~WrongCat();

		WrongCat	&operator=(const WrongCat &);
		void	makesound() const;
};

#endif
