#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name) { 
	if (grade > 150)
		throw TooLowException();
	else if (grade < 1)
		throw TooHighException();
	else 
		this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureau) {
	*this = bureau;
}

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

int	Bureaucrat::getGrade(void) const {
	return (grade);
}

const std::string	&Bureaucrat::getName(void) const {
	return (this->name);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &otherBureau)
{
	if (this != &otherBureau)
		this->grade = otherBureau.getGrade();
	return (*this);
}

void	Bureaucrat::upgrade(void)
{
	if (grade - 1 < 1)
		throw TooHighException();
	else
		grade--;
}

void	Bureaucrat::downgrade(void)
{
	if (grade + 1 > 150)
		throw TooLowException();
	else
		grade++;
}

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &otherBureau)
{
	ostream << otherBureau.getGrade() << ", bureaucrat grade " << otherBureau.getGrade() << '\n';
	return (ostream);
}

void	Bureaucrat::signForm(const std::string &formName, bool sign) const
{
	if (sign)
		std::cout << this->getName() << " signed " << formName << '\n';
	else
		std::cout << this->getName() << " couldn't sign " << formName << 
			" because his grade is too low" << '\n';
}
