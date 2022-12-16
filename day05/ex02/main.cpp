#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int	main(void)
{
	std::srand(time(NULL));
	Bureaucrat bla("truc", 150);
	Bureaucrat bla2("truc2", 1);
	//Bureaucrat bla3("truc3", 151);
	//Bureaucrat bla4("truc4", 0);
	AForm	*truc = new ShrubberyCreationForm("TREE");
	AForm	*truc2 = new PresidentialPardonForm("PRESIDENT");
	AForm	*truc3 = new RobotomyRequestForm("ROBOT");
	AForm	*truc4 = new ShrubberyCreationForm();
	std::cout << *truc4 << '\n';
	bla2.executeForm(*truc);
	bla.signForm(*truc);
	bla2.signForm(*truc);
	bla2.signForm(*truc2);
	bla2.signForm(*truc3);
	bla2.signForm(*truc3);
	bla.executeForm(*truc);
	bla2.executeForm(*truc);
	bla2.executeForm(*truc2);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	bla2.executeForm(*truc3);
	delete truc;
	delete truc2;
	delete truc3;
}
