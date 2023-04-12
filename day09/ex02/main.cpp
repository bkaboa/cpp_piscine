#include "PmergeMe.hpp"

int main(const int argc, const char **argv)
{
	PmergeMe sort(argv);
	PmergeMe truc;
	truc = sort;
	truc.beginSort();
}
