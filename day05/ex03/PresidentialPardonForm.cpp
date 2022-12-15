#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("PresidentialPardonForm", 5, 25) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm("PresidentialPardonForm",5, 25), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other.getName(), other.getExecGrade(), other.getSignGrade()) {
	this->target = other.getTarget();
	*this = other;
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->setIsSigned(other.getSign());
		this->setTarget(other.getTarget());
	}
	return (*this);
}

bool	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSign())
		throw FormNotSigned();
	else if (this->getExecGrade() < executor.getGrade())
		throw GradeTooHightExceptionExecution();
	else 
	{
		std::cout << this->getTarget() << " he is forgive by Zaphod beedlebrox" << '\n';
		return (true);
	}
	return (false);
}

const std::string	&PresidentialPardonForm::getTarget(void) const {
	return (target);
}

void	PresidentialPardonForm::setTarget(const std::string &target){
	this->target = target;
}
