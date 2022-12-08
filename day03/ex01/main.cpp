#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap	clapTrap("clap");
	ClapTrap	bla;

	std::cout << clapTrap << '\n';

	clapTrap.attack("truc");
	std::cout << '\n';
	clapTrap.takeDamage(5);
	std::cout << '\n';
	clapTrap.beRepaired(12);
	std::cout << '\n';
	clapTrap.takeDamage(50);
	std::cout << '\n';
	clapTrap.beRepaired(12);

	std::cout << '\n';
	std::cout << clapTrap << '\n';
	std::cout << '\n';

	bla = clapTrap;
	std::cout << '\n';
	std::cout << bla  << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';

	ScavTrap	scav("scav");
	std::cout << '\n';
	std::cout << '\n';
	ScavTrap	truc;
	std::cout << '\n';
	std::cout << '\n';
	std::cout << scav << '\n';
	std::cout << '\n';
	std::cout << '\n';
	scav.attack(bla.getName());
	std::cout << '\n';
	scav.takeDamage(5);
	std::cout << '\n';
	scav.beRepaired(12);
	std::cout << '\n';
	scav.takeDamage(50);
	std::cout << '\n';
	scav.beRepaired(12);
	std::cout << '\n';
	std::cout << '\n';
	std::cout << scav << '\n';
	std::cout << '\n';
	std::cout << '\n';

	truc = scav;
	std::cout << truc << '\n';
	std::cout << '\n';
	std::cout << '\n';
	truc.guardGate();
	return (0);
}
