#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(const std::string name): ClapTrap(name, 100, 50, 20) {}

ScavTrap::~ScavTrap() {}

void	ScavTrap::attack(const std::string &target)
{
}
