#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	jeanMichel;
	if (ac != 2)
	{
		std::cout << "need 1 arg" << '\n';
		return (0);
	}
	jeanMichel.complain(av[1]);
	return (0);
}
