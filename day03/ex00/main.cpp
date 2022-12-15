#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	clapTrap("clap");
	ClapTrap	bla;
	ClapTrap	bla2("bla");

	std::cout << clapTrap << '\n';

	clapTrap.attack("truc");
	clapTrap.takeDamage(5);
	clapTrap.beRepaired(12);
	clapTrap.takeDamage(50);
	clapTrap.beRepaired(12);

	std::cout << clapTrap << '\n';

	bla = clapTrap;
	std::cout << bla  << '\n';
	std::cout << bla2  << '\n';
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	bla2.attack("ouioui");
	return (0);
}
