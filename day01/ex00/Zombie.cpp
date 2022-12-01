#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "new zombie have been created\n";
}

Zombie::Zombie(std::string name):name(name)
{
	std::cout << "new zombie have been created\n";
}

Zombie::~Zombie()
{
	std::cout << "zombie " << this->name << " have been destruct\n";
}

void	Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << '\n';
}
