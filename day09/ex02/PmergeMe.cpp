#include "PmergeMe.hpp"
#include <ctime>
#include <vector>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const char **argv) {
	setArgs(argv);
}

PmergeMe::PmergeMe(const PmergeMe &otherPmergeMe) {
	*this = otherPmergeMe;
}

PmergeMe::~PmergeMe() {
	args.clear();
	vector.clear();
	list.clear();
}


std::string	PmergeMe::getArgs() const {
	return (args);
}

std::vector<long> PmergeMe::getSortVector() const {
	return (vector);
}

std::list<long> PmergeMe::getSortList() const {
	return (list);
}



void	PmergeMe::setArgs(const char **argv)
{
	int i = 1;

	args.assign(argv[i]);
	while (argv[++i])
	{
		args.push_back(' ');
		args.assign(argv[i]);
	}
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &otherPmergeMe) {
	if (this != &otherPmergeMe)
	{
		this->vector = otherPmergeMe.getSortVector();
		this->list = otherPmergeMe.getSortList();
		this->args = otherPmergeMe.getArgs();
	}
	return (*this);
}

void	PmergeMe::insertionSortList(int start, int end)
{
	int j = 0;
	long temp = 0;
	for (int i = start; start < end; i++)
	{
		j = i + 1;
		temp = listAt(list, j);
		while (j > start && listAt(list, j - 1) > temp)
		{
			listAt(list, j) = listAt(list, j - 1);
			j--;
		}
		listAt(list, j) = temp;
	}
}

void	PmergeMe::mergeList(int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;
	int startIdx = 0;
	int midIdx = 0;
	long startToMiddle[n1];
	long middleToEnd[n2];
	std::list<long>::iterator it = list.begin();

	for (int i = 0; i < start; i++)
		it++;
	for (int i = start; i < middle - 1; i++)
	{
		startToMiddle[i] = *it;
		it++;
	}
	for (int i = middle; i < end; i++)
	{
		middleToEnd[i] = *it;
		it++;
	}
	it = list.begin();
	for (int i = 0; i < start; i++)
		it++;
	for (int i = start; i < end - start + 1; i++, it++)
	{
		if (midIdx == n2) {
            *it = startToMiddle[startIdx];
            startIdx++;
        } else if (startIdx == n1) {
            *it = middleToEnd[midIdx];
            midIdx++;
        } else if (middleToEnd[midIdx] > startToMiddle[startIdx]) {
            *it = startToMiddle[startIdx];
            startIdx++;
        } else {
            *it = middleToEnd[midIdx];
            midIdx++;
		}
	}

}

void	PmergeMe::sortList(int start, int end)
{
	if (end - start > 15)
	{
		int middle = (start + end) / 2;
		sortList(start, middle);
		sortList(middle, end);
		mergeList(start, middle, end);
	}
	else
		insertionSortList(start, end);
}

long	&PmergeMe::listAt(std::list<long> &l, int index)
{
	if (index < 0 || index > static_cast<int>(l.size()))
		throw std::out_of_range("Index out of range");
	typename std::list<long>::iterator it = l.begin();
	for (int i = 0; i < index; i++, it++);
	return (*it);
}

void	PmergeMe::insertionSortVector(int start, int end)
{
	int j = 0;
	int temp = 0;
	for (int i = start; start < end; i++)
	{
		j = i + 1;
		temp = vector[j];
		while (j > start && vector[j - 1] > temp)
		{
			vector[j] = vector[j - 1];
			j--;
		}
		vector[j] = temp;
	}
}

void	PmergeMe::mergeVector(int start, int middle, int end)
{
	int n1 = middle - start + 1;
	int n2 = end - middle;
	int startIdx = 0;
	int midIdx = 0;
	long startToMiddle[n1];
	long middleToEnd[n2];

	for (int i = 0; i < n1; i++)
		startToMiddle[i] = vector[i];
	for (int i = n1; i < n2; i++)
		middleToEnd[i] = vector[i];
	for (int i = start; i < end - start + 1; i++)
	{
		if (midIdx == n2) {
            vector[i] = startToMiddle[startIdx];
            startIdx++;
        } else if (startIdx == n1) {
            vector[i] = middleToEnd[midIdx];
            midIdx++;
        } else if (middleToEnd[midIdx] > startToMiddle[startIdx]) {
            vector[i] = startToMiddle[startIdx];
            startIdx++;
        } else {
            vector[i] = middleToEnd[midIdx];
            midIdx++;
		}
	}
}

void	PmergeMe::sortVector(int start, int end)
{
	if (end - start > 15)
	{
		int middle = (start + end) / 2;
		sortVector(start, middle);
		sortVector(middle, end);
		mergeVector(start, middle, end);
	}
	else
		insertionSortVector(start, end);
}

void	PmergeMe::beginSort()
{
	if (args.find_first_not_of(VALIDC) != std::string::npos)
	{
		std::cout << "arguments can only be with numbers and space" << '\n';
		return ;
	}
}

