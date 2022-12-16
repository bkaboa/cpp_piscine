#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("pierre", "RobotomyRequestForm", 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm(target, "RobotomyRequestForm", 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other.getTarget(), other.getName(), other.getExecGrade(), other.getSignGrade()) {
	*this = other;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSign())
		throw FormNotSigned();
	else if (this->getExecGrade() < executor.getGrade())
		GradeTooLowException();
	else 
	{
		if (rand() % 2)
			std::cout << "brrrrrr AHAHAH it's a success " << this->getTarget() << " it's alive" << '\n';
		else 
			std::cout << "brrrr i killed it " << this->getTarget() << " get me another formular" << '\n';
	}
}

const RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->setIsSigned(other.getSign());
	return (*this);
}
