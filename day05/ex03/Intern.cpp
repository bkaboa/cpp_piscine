#include "Intern.hpp"
#include "Form.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &intern) {
	*this = intern;
}

AForm	*Intern::makeForm(std::string &name, std::string &target)
{
	std::string	formName[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	switch (str2int(name)) {
	
	}
}
