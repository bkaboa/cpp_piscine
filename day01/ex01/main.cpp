#include "Zombie.hpp"

int main(void)
{
	Zombie	*hordeZ = zombieHorde(10, "george");

	for (int i = 0; i < 10; i++)
		hordeZ[i].announce();
	delete [] hordeZ;
}
