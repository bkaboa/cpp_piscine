#include "PmergeMe.hpp"
#include <cctype>
#include <ctime>
#include <stdexcept>

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

long	PmergeMe::getListAt(int index)
{
	std::list<long>::iterator it = list.begin();
	if (index < 0 || index > static_cast<int>(list.size()))
		throw PmergeMeError("index out of range");
	for (int i = 0; i < index; i++)
		it++;
	return (*it);
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

void	PmergeMe::setListAt(int index, long num)
{
	if (index < 0 || index >= static_cast<int>(list.size()))	
		throw PmergeMeError("index out of range");
	std::list<long>::iterator it = list.begin();
	for (int i = 0; i < index; i++)
		it++;
	*it = num;
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &otherPmergeMe) {
	if (this != &otherPmergeMe)
		this->args = otherPmergeMe.getArgs();
	return (*this);
}

void	PmergeMe::insertionSortList(int start, int end)
{
	int j = 0;
	int temp = 0;
	for (int i = start; i < end; i++)
	{
		j = i + 1;
		temp = getListAt(j);
		while (j > start && getListAt(j - 1) > temp)
		{
			setListAt(j, getListAt(j - 1));
			j--;
		}
		setListAt(j, temp);
	}
}

void PmergeMe::mergeList(int start, int mid, int end) {
  
  int n1 = mid - start + 1;
  int n2 = end - mid;

  long startToMiddle[n1], middleToEnd[n2];

  for (int i = 0; i < n1; i++)
    startToMiddle[i] = getListAt(start + i);
  for (int j = 0; j < n2; j++)
    middleToEnd[j] = getListAt(mid + 1 + j);

  int i, j, k;
  i = 0;
  j = 0;
  k = start;

  while (i < n1 && j < n2) {
    if (startToMiddle[i] <= middleToEnd[j]) {
      setListAt(k, startToMiddle[i]);
      i++;
    } else {
      setListAt(k, middleToEnd[j]);
      j++;
    }
    k++;
  }

  while (i < n1) {
    setListAt(k, startToMiddle[i]);
    i++;
    k++;
  }

  while (j < n2) {
    setListAt(k, middleToEnd[j]);
    j++;
    k++;
  }
}

void	PmergeMe::mergeSortList(int start, int end)
{
	if (start + 15 < end) {
  	  int mid = start + (end - start) / 2;
  	  mergeSortList(start, mid);
  	  mergeSortList(mid + 1, end);
  	  mergeList(start, mid, end);
  	}
	else
		insertionSortList(start, end);
}

void	PmergeMe::insertionSortVector(int start, int end)
{
	int j = 0;
	int temp = 0;
	for (int i = start; i < end; i++)
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

void PmergeMe::mergeVector(int start, int mid, int end) {
  
  int n1 = mid - start + 1;
  int n2 = end - mid;

  int startToMiddle[n1], middleToEnd[n2];

  for (int i = 0; i < n1; i++)
    startToMiddle[i] = vector[start + i];
  for (int j = 0; j < n2; j++)
    middleToEnd[j] = vector[mid + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = start;

  while (i < n1 && j < n2) {
    if (startToMiddle[i] <= middleToEnd[j]) {
      vector[k] = startToMiddle[i];
      i++;
    } else {
      vector[k] = middleToEnd[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    vector[k] = startToMiddle[i];
    i++;
    k++;
  }

  while (j < n2) {
    vector[k] = middleToEnd[j];
    j++;
    k++;
  }
}

void PmergeMe::mergeSortVector(int start, int end) {
	if (start + 15 < end) {
  	  int mid = start + (end - start) / 2;
  	  mergeSortVector(start, mid);
  	  mergeSortVector(mid + 1, end);
  	  mergeVector(start, mid, end);
  	}
	else
		insertionSortVector(start, end);
}

void	PmergeMe::beginSort()
{
	clock_t	t1 = 0 ,t2 = 0;

	if (args.empty())
		throw PmergeMeError("Error : no args");
;
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
	mergeSortList(0, list.size() - 1);
	t2 = clock();
	std::cout << "Time to process a range of " << list.size() << " elements with std::list  : " << ((float)t2 - (float)t1) / 1000.0F << " ms" << '\n';
	t1 = clock();
	mergeSortVector(0, vector.size() - 1);
	t2 = clock();
	std::cout << "Time to process a range of " << vector.size() << " elements with std::vector  : " << ((float)t2 - (float)t1) / 1000.0F << " ms" << '\n';
	std::cout << "after: ";
	for (std::list<long>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
}

