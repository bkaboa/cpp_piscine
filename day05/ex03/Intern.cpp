#include "Intern.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	int i;
	std::string	formName[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	for (i = 0; i < 3 && name != formName[i]; i++);
	switch (i)
	{
		case 0:
			return (new PresidentialPardonForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new ShrubberyCreationForm(target));
		default:
			throw InternMakeException();
	}
	return (NULL);
}
