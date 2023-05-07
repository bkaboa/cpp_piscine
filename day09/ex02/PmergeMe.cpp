#include "PmergeMe.hpp"
#include <cctype>
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
	int number;

	if (!vector.empty())
		vector.clear();
	for (std::string::iterator it = args.begin(); it != args.end(); it++)
	{
		if (std::isalnum(*it))
		{
			if ((number = std::atoi((const char*)it.base())) < 0)
				throw PmergeMeError("only positive numbers are valid");
			vector.push_back(number);
			while (it < args.end() && std::isalnum(*it))
				it++;
		}
	}
	if (vector.empty())
		throw PmergeMeError("Error : only spce with no numbers are present in argv");
}

void	PmergeMe::setList()
{
	int number;

	if (!list.empty())
		list.clear();
	for (std::string::iterator it = args.begin(); it != args.end(); it++)
	{
		if (std::isalnum(*it))
		{
			if ((number = std::atoi((const char*)it.base())) < 0)
				throw PmergeMeError("only positive numbers are valid");
			list.push_back(number);
			while (it < args.end() && std::isalnum(*it))
				it++;
		}
	}
	if (list.empty())
		throw PmergeMeError("Error : only spce with no numbers are present in argv");
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
	if (args.find_first_not_of(VALIDC) != std::string::npos)
	{
		std::cout << "arguments can only be with numbers and space" << '\n';
		return ;
	}
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

