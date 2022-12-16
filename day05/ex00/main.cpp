#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat bla("truc", 150);
	Bureaucrat bla2("truc2", 1);
	Bureaucrat bla3("truc3", 40);
	//Bureaucrat bla3("truc3", 151);
	//Bureaucrat bla4("truc4", 0);
	try {
		bla.downgrade();
	} catch (std::exception &e) {
		std::cout << bla << '\n';
		std::cout << "\x1B[31m" << e.what() << "\x1b[0m" << '\n';
	}

	std::cout << '\n';

	try {
	bla2.upgrade();
	} catch (std::exception &e) {
		std::cout << bla2 << '\n';
		std::cout << "\x1B[31m" << e.what() << "\x1b[0m" << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';
	std::cout << bla3 << '\n';
	bla3.downgrade();
	std::cout << bla3 << '\n';
}
