#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clapTrap("clap");
	ClapTrap	bla;

	std::cout << clapTrap << '\n';

	clapTrap.attack("truc");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(12);
	clapTrap.takeDamage(50);
	clapTrap.beRepaired(12);

	std::cout << clapTrap << '\n';

	bla = clapTrap;
	std::cout << bla  << '\n';
	return (0);
}
