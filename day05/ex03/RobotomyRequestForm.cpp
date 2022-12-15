#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 45, 72) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 45, 72), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):AForm(other.getName(), other.getExecGrade(), other.getSignGrade()) {
	this->target = other.getTarget();
	*this = other;
}

bool	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getSign())
		throw FormNotSigned();
	else if (this->getExecGrade() < executor.getGrade())
		throw GradeTooHightExceptionExecution();
	else
	{
		if (rand() % 2)
			std::cout << "brrrrrr AHAHAH it's a success " << this->getTarget() << " it's alive" << '\n';
		else 
			std::cout << "brrrr i killed it " << this->getTarget() << " get me another formular" << '\n';
		return (true);
	}
	return (false);
}

const RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		this->setTarget(other.getTarget());
		this->setIsSigned(other.getSign());
	}
	return (*this);
}

const std::string	&RobotomyRequestForm::getTarget(void) const {
	return (target);
}

void	RobotomyRequestForm::setTarget(const std::string &target){
	this->target = target;
}
