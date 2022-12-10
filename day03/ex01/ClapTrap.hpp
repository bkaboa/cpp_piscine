#ifndef CLAPTRAP
# define CLAPTRAP

# include <string>
# include <iostream>

# define CONSTRUCTOR		"claptrap constructor called"
# define CONSTRUCTOR_PARAM	"claptrap parametic constructor called"
# define COPY_CONSTRUCTOR	"claptrap copy constructor called"
# define DESTRUCTOR			"claptrap destructor called"
# define ASSIGNEMENT		"claptrap copy assignement called"

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;

	public:
		ClapTrap();
		ClapTrap(const std::string&);
		ClapTrap(const ClapTrap &clap);
		~ClapTrap();

		ClapTrap(std::string, int, int, int);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const std::string	&getName(void) const;
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
