#include "Weapon.hpp"

Weapon::Weapon(std::string type):type(type) {}

Weapon::Weapon() {}

Weapon::~Weapon() {}

std::string	Weapon::getType(void) const
{
	return (this->type);
}

void	Weapon::setType(const std::string type)
{
	this->type = type;
}
