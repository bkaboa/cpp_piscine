#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap truc("truc");
	std::cout << '\n';
	std::cout << '\n';
	FragTrap bla(truc);
	std::cout << '\n';
	std::cout << '\n';
	std::cout << truc << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << bla << '\n';
	std::cout << '\n';
	std::cout << '\n';
	bla.highFivesGuys();
	std::cout << '\n';

	return (0);
}
