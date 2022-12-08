#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clapTrap("clap");

	std::cout << clapTrap << '\n';

	clapTrap.attack("truc");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(12);

	std::cout << clapTrap << '\n';
	return (0);
}
