#ifndef CLAPTRAP
# define CLAPTRAP

#include <ostream>
# include <string>
# include <iostream>

# define CONSTRUCTOR		"constructor called"
# define CONSTRUCTOR_PARAM	"parametic constructor called"
# define COPY_CONSTRUCTOR	"copy constructor called"
# define DESTRUCTOR			"destructor called"
# define ASSIGNEMENT		"copy assignement called"

class ClapTrap
{
	private:
		std::string	Name;
		int			Hit;
		int			Energy;
		int			Attack;

	public:
		ClapTrap();
		ClapTrap(const std::string);
		ClapTrap(const ClapTrap &clap);
		~ClapTrap();

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHit(void) const;
		int			getEnergy(void) const;
		int			getAttack(void) const;

		void	setName(const std::string);

		ClapTrap &operator=(const ClapTrap &);
};

std::ostream &operator<<(std::ostream &, const ClapTrap &);

#endif
