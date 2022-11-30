#include <cctype>
#include <iostream>
#include <cstdio>

int main(int ac, char **av)
{
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
