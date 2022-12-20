#ifndef MUTANTSTACK
# define MUTANTSTACK

# include <deque>
# include <stack>
# include <string>
# include <iostream>
# include <list>

template<typename T>
class MutantStack:public std::stack<T>
{
	public:
		MutantStack():std::stack<T>() {}
		MutantStack(const MutantStack &other):std::stack<T>(other) {}
		virtual ~MutantStack() {}

		MutantStack	&operator=(const MutantStack &other)
		{
			if (this != &other)
				std::stack<T>::operator=(other);
			return (other);
		}

		typedef typename std::deque<T>::iterator iterator;
		iterator	begin(void) {return (std::stack<T>::c.begin());}
		iterator	end(void) {return (std::stack<T>::c.end());}
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		reverse_iterator	rbegin(void) {return (std::stack<T>::c.rbegin());}
		reverse_iterator	rend(void) {return (std::stack<T>::c.rend());}
};

#endif
