#ifndef FRAGTRAP
# define FRAGTRAP

# include "ClapTrap.hpp"

# define FRAG_CONSTRUCTOR		"scavtrap constructor called"
# define FRAG_CONSTRUCTOR_PARAM	"scavtrap parametic constructor called"
# define FRAG_COPY_CONSTRUCTOR	"scavtrap copy constructor called"
# define FRAG_DESTRUCTOR		"scavtrap destructor called"
# define FRAG_ASSIGNEMENT		"scavtrap copy assignement called"

class FragTrap : public ClapTrap
{
	public:
		void	highFivesGuys(void);
		FragTrap();
		FragTrap(const std::string &);
		FragTrap(const FragTrap &);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &);
};

std::ostream &operator<<(std::ostream &, const FragTrap &);

#endif
