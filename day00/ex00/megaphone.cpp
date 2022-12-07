#include <cctype>
#include <iostream>
#include <cstdio>

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	for(int i = 1; i < ac; i++)
	{
		while (*(av[i]))
		{
			std::cout << (char)std::toupper((*(av[i])));
			(av[i])++;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
