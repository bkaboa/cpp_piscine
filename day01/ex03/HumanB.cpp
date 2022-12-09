#include "HumanB.hpp"

HumanB::HumanB(const std::string name):name(name) {}

HumanB::HumanB(const std::string name, Weapon weapon): name(name), weapon(weapon) {}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon weapon)
{
	(this->weapon) = weapon;
}

void	HumanB::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}

