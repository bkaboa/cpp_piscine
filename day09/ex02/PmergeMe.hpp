#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <list>
#include <vector>

#define VALIDC	"0123456789 "

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const char**);
	PmergeMe(const PmergeMe&);
	~PmergeMe();
	
	void				setArgs(const char **);
	std::string			getArgs() const;
	std::vector<long>	getSortVector() const;
	std::list<long>		getSortList() const;

	PmergeMe &operator=(const PmergeMe&);

	void	beginSort();

private:
	void	insertionSortVector(int, int);
	void	mergeVector(int, int, int);
	void	sortVector(int, int);
	void	insertionSortList(int, int);
	void	mergeList(int, int, int);
	void	sortList(int, int);
	bool	setList();
	bool	setVector();

	long	&listAt(std::list<long> &l, int index);

	std::string			args;
	std::vector<long>	vector;
	std::list<long>		list;
};

#endif // !PMERGEME_HPP
