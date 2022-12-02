#include "HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon &weapon):name(name), weapon(weapon) {}

HumanA::~HumanA() {}

void	HumanA::attack(void) const
{
	std::cout << name << " attacks with their " << weapon.getType() << '\n';
}
