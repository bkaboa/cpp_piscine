#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {}

ClapTrap::ClapTrap(const std::string Name):Name(Name), Hit(10), Energy(10), Attack(0) {}

ClapTrap::ClapTrap(const ClapTrap &clap) {
	*this = clap;
}

void	ClapTrap::attack(const std::string &target) {
	this->Energy -= 1;
	std::cout << Name << " attack " << target << '\n';
	std::cout << Name << " rest " << Energy << " point" << '\n';
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->Hit -= amount;
	std::cout << Name << " take " << amount << " damage" << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount) {
	this->Hit += amount;
	std::cout << Name << " repaired " << amount << " Hit point" << '\n';
}
