#include "Zombie.hpp"

int main(void)
{
	Zombie	*newZ = newZombie("truc");
	randomChump("hehe");
	newZ->announce();
	delete newZ;
}
