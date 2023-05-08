#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <string>
#include <iostream>
#include <list>
#include <vector>
#include <exception>
#include <cstdlib>
#include <algorithm>

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

private:

	template<class Iter>
	void	mergeSort(Iter, Iter);

	template<class Iter>
	void	insertionSort(Iter, Iter);

	void	setList();
	void	setVector();

	std::string			args;
	std::vector<long>	vector;
	std::list<long>		list;
};

#endif // !PMERGEME_HPP
