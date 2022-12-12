#ifndef BRAIN_CLASS
# define BRAIN_CLASS

# include "Animal.class.hpp"

# define B_CONSTRUCTOR			"Brain constructor called"
# define B_CONSTRUCTOR_PARAM	"Brain parameter constructor called"
# define B_CONSTRUCTOR_COPY		"Brain copy constructor called"
# define B_DESTRUCTOR			"Brain destructor called"

class	Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const std::string);
		Brain(const Brain&);
		~Brain();

		const std::string	*getIdeas(void) const;
		void	printIdeas(void)	const;
		Brain &operator=(const Brain &);
};

#endif
