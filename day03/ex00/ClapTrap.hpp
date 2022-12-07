#ifndef CLAPTRAP
# define CLAPTRAP

# include <string>
# include <iostream>

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
		void	setName(const std::string);
};

#endif
