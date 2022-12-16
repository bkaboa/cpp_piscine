#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("jean", "PresidentialPardonForm", 5, 25) {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):AForm(target, "PresidentialPardonForm",5, 25) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):AForm(other.getTarget(), other.getName(), other.getExecGrade(), other.getSignGrade()) {
	*this = other;
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->setIsSigned(other.getSign());
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSign())
		throw FormNotSigned();
	else if (this->getExecGrade() < executor.getGrade())
		GradeTooLowException();
	else 
	{
		std::cout << this->getTarget() << " he is forgive by Zaphod beedlebrox" << '\n';
	}
}
