#include "Form.hpp"

AForm::AForm():sign(false), execGrade(150), signGrade(150) {}

AForm::AForm(const std::string &name,int execlvl,int signlvl):name(name), sign(false), execGrade(execlvl), signGrade(signlvl) {
	if (execlvl < 1 || signlvl < 1)
		throw GradeTooHightException();
	else if (execlvl > 159 || signlvl > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &otherForm) : name(otherForm.name), sign(otherForm.sign), execGrade(otherForm.execGrade), signGrade(otherForm.signGrade) {
	*this = otherForm;
}

AForm::~AForm() {}

void	AForm::beSigned(const Bureaucrat &bureaucrat)
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
		this->setIsSigned(true);
		bureaucrat.signForm(this->getName(), this->getSign());
	}
}

const AForm	&AForm::operator=(const AForm &otherForm)
{
	if (this != &otherForm)
		this->sign = otherForm.getSign();
	return (*this);
}

int	AForm::getExecGrade(void) const {
	return (execGrade);
}

int	AForm::getSignGrade(void) const {
	return (signGrade);
}

bool	AForm::getSign(void) const {
	return (sign);
}

const std::string	&AForm::getName(void) const {
	return (name);
}

void	AForm::setIsSigned(bool) {
	this->sign = true;
}

std::ostream	&operator<<(std::ostream &ostream, const AForm &otherForm)
{
	ostream << "form name " << otherForm.getName() << '\n';
	ostream << "form sign " << (otherForm.getSign() ? " is ok " : " is not ok") << '\n';
	ostream << "execute level " << otherForm.getExecGrade() << '\n';
	ostream << "signe level " << otherForm.getSignGrade() << '\n';
	return (ostream);
}
