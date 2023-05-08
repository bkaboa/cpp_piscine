#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <stdexcept>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const char **argv) {
	setArgs(argv);
}

PmergeMe::PmergeMe(const PmergeMe &otherPmergeMe) {
	*this = otherPmergeMe;
}

PmergeMe::~PmergeMe() {}

const std::string	&PmergeMe::getArgs() const {
	return (args);
}

void		PmergeMe::setVector()
{
	long	number;
	char	*end;
	std::string::iterator it = args.begin();

	if (!vector.empty())
		vector.clear();
	for (; it != args.end(); it++)
	{
		number = std::strtol(it.base(), &end, 10);
		if (!std::isspace(*end) && !std::isdigit(*end))
			throw PmergeMeError("Error : syntax");
		if (it.base() == end)
			break;
		if (number < 0)
			throw PmergeMeError("Error : only positive number are valid");
		vector.push_back(number);
		while (it.base() != end)
			it++;
	}
	if (vector.empty())
		throw PmergeMeError("Error : no numbers in args");
}

void	PmergeMe::setList()
{
	long	number;
	char	*end;
	std::string::iterator it = args.begin();

	if (!list.empty())
		list.clear();
	for (; it != args.end(); it++)
	{
		number = std::strtol(it.base(), &end, 10);
		if (!std::isspace(*end) && !std::isdigit(*end))
			throw PmergeMeError("Error : syntax");
		if (it.base() == end)
			break;
		if (number < 0)
			throw PmergeMeError("Error : only positive number are valid");
		list.push_back(number);
		while (it.base() != end)
			it++;
	}
	if (list.empty())
		throw PmergeMeError("Error : no numbers in args");
}

void	PmergeMe::setArgs(const char **argv)
{
	int i = 0;
	int j = 0;

	if (!args.empty())
		args.clear();
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
			args.push_back(argv[i][j++]);
		args.push_back(' ');
	}
	if (args.empty())
		throw PmergeMeError("Error : no args");
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &otherPmergeMe) {
	if (this != &otherPmergeMe)
		this->args = otherPmergeMe.getArgs();
	return (*this);
}

template<class Iter>
void	PmergeMe::mergeSort(Iter start, Iter end)
{
	if (std::distance(start, end) > 15) {
		Iter mid = start;
		std::advance(mid, std::distance(start, end) / 2);
  	  	mergeSort(start, mid);
  	  	mergeSort(mid, end);
		std::inplace_merge(start, mid, end);
  	}
	else
	{
		insertionSort(start, --end);
	}
}

template<class Iter>
void	PmergeMe::insertionSort(Iter start, Iter end)
{
	Iter	it;
	long	temp;
	while (end != start)
	{
		it = end;
		do 
		{
			if(*it > *end)
			{
				temp = *it;
				*it = *end;
				*end = temp;
			}
		}
		while (it-- != start);
		end--;
	}
}

void	PmergeMe::beginSort()
{
	clock_t	t1 = 0 ,t2 = 0;

	if (args.empty())
		throw PmergeMeError("Error : no args");
	setList();
	setVector();
	std::cout << "before: ";
	for (std::vector<long>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	t1 = clock();
	mergeSort(list.begin(), list.end());
	t2 = clock();
	std::cout << "Time to process a range of " << list.size() << " elements with std::list  : " << ((float)t2 - (float)t1) / 1000.0F << " ms" << '\n';
	t1 = clock();
	mergeSort(vector.begin(), vector.end());
	t2 = clock();
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector  : " << ((float)t2 - (float)t1) / 1000.0F << " ms" << '\n';
	std::cout << "after: ";
	for (std::list<long>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

