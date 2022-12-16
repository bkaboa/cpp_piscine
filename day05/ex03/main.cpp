#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

int	main(void)
{
	Intern	doWork;

	Bureaucrat jean("jean", 1);
	AForm *bla = doWork.makeForm("ShrubberyCreationForm", "tree");
	jean.executeForm(*bla);
	//AForm *bla2 = doWork.makeForm("fwoie", "truc");
	bla->beSigned(jean);
	bla->execute(jean);
	//bla2->beSigned(jean);
	//delete bla2
	delete bla;
}
