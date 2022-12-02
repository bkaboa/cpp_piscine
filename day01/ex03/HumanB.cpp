#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon weapon): name(name), weapon(weapon) {}

HumanB::HumanB(std::string name): name(name) {}

HumanB::~HumanB() {}

void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = weapon;
}
