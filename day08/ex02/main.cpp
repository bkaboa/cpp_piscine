#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "FIRST TEST" << '\n';
	std::cout << '\n';
	std::cout << '\n';
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::reverse_iterator itr = mstack.rbegin();
	MutantStack<int>::reverse_iterator itre = mstack.rend();
	std::cout << '\n';
	std::cout << '\n';
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << '\n';
	std::cout << '\n';
	while (itr != itre)
	{
		std::cout << *itr << std::endl;
		++itr;
	}
	std::stack<int> s(mstack);

	std::cout << "SECOND TEST" << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::list<int> list;
	list.push_back(5);
	list.push_back(17);
	std::cout << *--list.end() << std::endl;
	list.pop_back();
	std::cout << list.size() << std::endl;
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);
	std::list<int>::iterator itl = list.begin();
	std::list<int>::iterator itle = list.end();
	std::list<int>::reverse_iterator itlr = list.rbegin();
	std::list<int>::reverse_iterator itrle = list.rend();
	std::cout << '\n';
	std::cout << '\n';
	++itl;
	--itl;
	while (itl != itle)
	{
		std::cout << *itl << std::endl;
		++itl;
	}
	std::cout << '\n';
	std::cout << '\n';
	while (itlr != itrle)
	{
		std::cout << *itlr << std::endl;
		++itlr;
	}
	return 0;
}
