#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat bla("truc", 150);
	Bureaucrat bla2("truc2", 1);
	//Bureaucrat bla3("truc3", 151);
	//Bureaucrat bla4("truc4", 0);
	Form	truc("bla", 45, 45);
	try {
	truc.beSigned(bla);
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
		std::cout << truc << '\n';
	}
	try {
	truc.beSigned(bla2);
	} catch (std::exception &e) {
		std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
		std::cout << truc;
	}
	std::cout << '\n';
	std::cout << truc << '\n';
	std::cout << '\n';
	std::cout << '\n';
}
