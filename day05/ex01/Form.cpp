#include "Form.hpp"

Form::Form():sign(false), execGrade(150), signGrade(150) {}

Form::Form(const std::string &name,int execlvl,int signlvl):name(name), sign(false), execGrade(execlvl), signGrade(signlvl) {
	if (execlvl < 1 || signlvl < 1)
		throw GradeTooHightException();
	else if (execlvl > 159 || signlvl > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &otherForm) : name(otherForm.name), sign(otherForm.sign), execGrade(otherForm.execGrade), signGrade(otherForm.signGrade) {
	*this = otherForm;
}

Form::~Form() {}

void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->getSign())
		std::cout << "form " << this->getName() << " already signed" << '\n';
	else if (this->getSignGrade() < bureaucrat.getGrade())
	{
		throw GradeTooLowException();
		bureaucrat.signForm(this->getName(), this->getSign());
	}
	else
	{
		this->setIsSigned();
		bureaucrat.signForm(this->getName(), this->getSign());
	}
}

const Form	&Form::operator=(const Form &otherForm)
{
	if (this != &otherForm)
		this->sign = getSign();
	return (*this);
}

int	Form::getExecGrade(void) const {
	return (execGrade);
}

int	Form::getSignGrade(void) const {
	return (signGrade);
}

bool	Form::getSign(void) const {
	return (sign);
}

const std::string	&Form::getName(void) const {
	return (name);
}

void	Form::setIsSigned(void) {
	this->sign = true;
}

std::ostream	&operator<<(std::ostream &ostream, const Form &otherForm)
{
	ostream << "form name " << otherForm.getName() << '\n';
	ostream << "form sign " << (otherForm.getSign() ? " is ok " : " is not ok") << '\n';
	ostream << "execute level " << otherForm.getExecGrade() << '\n';
	ostream << "signe level " << otherForm.getSignGrade() << '\n';
	return (ostream);
}
