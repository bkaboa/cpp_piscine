#include "iter.hpp"

int main(void)
{
	int	nbr[] = {0, 0, 0, 0, 0};
	std::string str[] = {"truc", "machin", "bla"};

	std::cout << "print str" << '\n';
	std::cout << '\n';
	std::cout << '\n';
	iter(str, 3, &print);
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "print nbr" << '\n';
	std::cout << '\n';
	std::cout << '\n';
	iter(nbr, 5, &print);
	std::cout << "increment nbr" << '\n';
	iter(nbr, 5, &increment);
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "print nbr" << '\n';
	std::cout << '\n';
	std::cout << '\n';
	iter(nbr, 5, &print);
}

