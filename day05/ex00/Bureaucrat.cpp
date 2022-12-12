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
	ostream << "name : " << otherBureau.getGrade() << '\n';
	ostream << "grade : " << otherBureau.getName();
	return (ostream);
}

