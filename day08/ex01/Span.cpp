#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N):N(N), numbers(std::list<int>()) {}

Span::Span(const Span &span) {
	*this = span;
}

Span::~Span() {}

Span	&Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->N = other.N;
		this->numbers = other.numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (this->numbers.size() >= this->N)
		throw FullException();
	this->numbers.push_back(number);
}

void	Span::addNumbers(int lenght)
{
	while (this->numbers.size() < this->N && lenght-- > 0)
	{
		this->numbers.push_back(rand());
	}
	if (lenght > 0)
		throw FullException();
}

unsigned int	Span::shortestSpan(void) const
{
	if (this->numbers.size() < 2)
		throw ListException();
	std::list<int>sorted = this->numbers;
	sorted.sort();  

	int min = std::numeric_limits<int>::max();
  for (std::list<int>::iterator it = sorted.begin(); it != --sorted.end(); it++) {
    int diff = *++it - *--it;

    if (diff < min) {
      min = diff;
    }
  }
 return min;
}

unsigned int	Span::longestSpan(void) const
{
	if (this->numbers.size() < 2)
		throw ListException();
	std::list<int>sorted = this->numbers;
	sorted.sort();
	return (*--sorted.end() - *sorted.begin());
}

void	Span::print(void)
{
	for (std::list<int>::iterator it = this->numbers.begin(); it != this->numbers.end();it++)
		std::cout << *it << '\n';
}

void	Span::printSort(void)
{
	std::list<int> sorted = this->numbers;
	sorted.sort();
	for (std::list<int>::iterator it = sorted.begin(); it != sorted.end();it++)
		std::cout << *it << '\n';
}
