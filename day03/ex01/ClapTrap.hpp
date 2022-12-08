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
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;

	public:
		ClapTrap();
		ClapTrap(const std::string);
		ClapTrap(const ClapTrap &clap);
		~ClapTrap();

		ClapTrap(std::string, int, int, int);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHit(void) const;
		int			getEnergy(void) const;
		int			getAttack(void) const;

		void	setName(const std::string);
		void	setHit(const int);
		void	setenergy(const int);
		void	setattack(const int);

		ClapTrap &operator=(const ClapTrap &);
};

std::ostream &operator<<(std::ostream &, const ClapTrap &);

#endif
