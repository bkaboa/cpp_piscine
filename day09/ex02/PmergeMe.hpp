#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <exception>

#define VALIDC	"0123456789 "

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const char**);
	PmergeMe(const PmergeMe&);
	~PmergeMe();
	
	void				setArgs(const char **);
	const std::string	&getArgs() const;

	PmergeMe &operator=(const PmergeMe&);

	void	beginSort();

	class PmergeMeError : virtual public std::exception
	{
		private:
			std::string message;
		public:
			PmergeMeError(std::string msg):message(msg) {}
			virtual ~PmergeMeError() throw() {};
			virtual const char* what() const throw()
			{
				return (message.c_str());
			}
	};

	class emptyArgs: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error : no args");
			}
	};

	class onlySpaceInString: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error : only spce with no numbers are present in argv");
			}
	};

private:
	void	insertionSortVector(int, int);
	void	mergeVector(int, int, int);
	void	mergeSortVector(int, int);

	void	insertionSortList(int, int);
	void	mergeList(int, int, int);
	void	mergeSortList(int, int);

	void	setList();
	void	setVector();

	void	setListAt(int, long);
	long	getListAt(int);

	std::string			args;
	std::vector<long>	vector;
	std::list<long>		list;
};

#endif // !PMERGEME_HPP
