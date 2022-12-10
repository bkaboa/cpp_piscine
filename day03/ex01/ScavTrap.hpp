#ifndef SCAVTRAP
# define SCAVTRAP

# include "ClapTrap.hpp"

# define SCAV_CONSTRUCTOR		"scavtrap constructor called"
# define SCAV_CONSTRUCTOR_PARAM	"scavtrap parametic constructor called"
# define SCAV_COPY_CONSTRUCTOR	"scavtrap copy constructor called"
# define SCAV_DESTRUCTOR		"scavtrap destructor called"
# define SCAV_ASSIGNEMENT		"scavtrap copy assignement called"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const ScavTrap &);
		ScavTrap();
		ScavTrap(const std::string&);
		~ScavTrap();

		void	guardGate();

		ScavTrap &operator=(const ScavTrap &);

		void	attack(const std::string &);
};

std::ostream &operator<<(std::ostream &, const ScavTrap &);

#endif
