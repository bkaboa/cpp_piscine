#include "Span.hpp"
#include <climits>

int main(void)
{
	std::cout << "first test" << '\n';
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "second test" << '\n';
	Span truc = Span(2);
	truc.addNumber(4);
	try {
		truc.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	try {
		truc.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	truc.addNumber(3);
	std::cout << truc.longestSpan() << '\n';
	std::cout << truc.shortestSpan() << '\n';
	try {
		truc.addNumber(2);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "third test" << '\n';
	Span truc2 = Span(2);
	truc2.addNumber(2);
	truc2.addNumber(2);
	std::cout << truc2.longestSpan() << '\n';
	std::cout << truc2.shortestSpan() << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "fourth test" << '\n';
	Span truc3 = Span(10000);
	truc3.addNumbers(10000);
	std::cout << truc3.longestSpan() << '\n';
	std::cout << truc3.shortestSpan() << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "fifth test" << '\n';
	Span truc4 = Span(0);
	try {
		truc4.longestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	try {
		truc4.shortestSpan();
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "sixth test" << '\n';
	Span truc5 = Span(2);
	truc5.addNumber(INT_MAX);
	truc5.addNumber(INT_MIN);
	std::cout << truc5.longestSpan() << '\n';
	std::cout << truc5.shortestSpan() << '\n';
}
