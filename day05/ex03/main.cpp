#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Intern	doWork;

	Bureaucrat jean("jean", 1);
	AForm *bla = doWork.makeForm("RobotomyRequestForm", "robot");
	AForm *bla2 = doWork.makeForm("ShrubberyCreationForm", "tree");
	AForm *bla3 = doWork.makeForm("PresidentialPardonForm", "jean");
	//AForm *bla4 = doWork.makeForm("PresidennForm", "jean");
	jean.executeForm(*bla);
	jean.signForm(*bla);
	jean.executeForm(*bla);
	jean.signForm(*bla2);
	jean.executeForm(*bla2);
	jean.signForm(*bla3);
	jean.executeForm(*bla3);
	//jean.executeForm(*bla4);
	delete bla;
	delete bla2;
	delete bla3;
}
