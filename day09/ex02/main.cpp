#include "PmergeMe.hpp"

int main(const int argc, const char **argv)
{
	if (argc >= 10000)
	{
		std::cout << "Error: are you crazy that's too much number" << '\n';
		return (1);
	}
	try {
		PmergeMe insertMergeAlgo(argv);
		insertMergeAlgo.beginSort();
	} catch (const std::exception &e) {
		std::cout << e.what() << '\n';
	}
}
