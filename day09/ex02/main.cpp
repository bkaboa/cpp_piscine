#include "PmergeMe.hpp"

int main(const int argc, const char **argv)
{
	if (argc >= 10000)
	{
		std::cout << "Error: are you crazy that's too much number" << '\n';
		return (1);
	}
	PmergeMe insertMergeAlgo(argv);
	insertMergeAlgo.beginSort();
}
