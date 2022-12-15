#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int	main(void)
{
	Bureaucrat bla("truc", 150);
	Bureaucrat bla2("truc2", 1);
	//Bureaucrat bla3("truc3", 151);
	//Bureaucrat bla4("truc4", 0);
	std::srand(time(NULL));
	AForm	*truc = new ShrubberyCreationForm("truc");
	AForm	*truc2 = new PresidentialPardonForm("jean");
	AForm	*truc3 = new RobotomyRequestForm("george");
	try {
		truc->beSigned(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc << '\n';
	}
	try {
		truc->execute(bla);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	try {
		truc->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	try {
		truc3->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc3 << '\n';
	}
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	try {
		truc3->beSigned(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc3 << '\n';
	}
	try {
		truc3->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc3 << '\n';
	}
	try {
		truc3->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc3 << '\n';
	}
	try {
		truc3->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc3 << '\n';
	}
	try {
		truc3->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc3 << '\n';
	}
	try {
		truc3->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc3 << '\n';
	}
	try {
		truc2->execute(bla2);
	} catch (std::exception &e) {
			std::cout << "\x1B[31m" << e.what() << "\x1B[0m" << '\n';
			std::cout << *truc2 << '\n';
	}
	delete truc;
	delete truc2;
	delete truc3;
}
