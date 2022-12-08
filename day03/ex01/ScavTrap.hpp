#ifndef SCAVTRAP
# define SCAVTRAP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const ScavTrap &);
		ScavTrap(const std::string);
		~ScavTrap();

		void	guardGate();

		ClapTrap &operator=(const ClapTrap &);
};

std::ostream &operator<<(std::ostream &, const ClapTrap &);

#endif
