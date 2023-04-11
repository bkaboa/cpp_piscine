#include "PmergeMe.hpp"

int main(const int argc, const char **argv)
{
	if (argc == 1)
	{
		std::cout << "need at least 1 argument" << '\n';
		return (1);
	}
	PmergeMe sort(argv);
}
