#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "new zombie have been created\n";
}

Zombie::~Zombie()
{
	std::cout << "zombie " << this->name << " have been destruct\n";
}

void	Zombie::setname(std::string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n';
}
