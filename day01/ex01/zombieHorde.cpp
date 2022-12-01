#include "Zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*newHordeZ = new Zombie[N];
	for (int i = 0; i < N; i++)
		newHordeZ[i].setname(name);
	return (newHordeZ);
}
