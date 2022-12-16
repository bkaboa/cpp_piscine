#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade): name(name) { 
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
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
		throw GradeTooHighException();
	else
		grade--;
}

void	Bureaucrat::downgrade(void)
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	else
		grade++;
}

std::ostream	&operator<<(std::ostream &ostream, const Bureaucrat &otherBureau)
{
	ostream << otherBureau.getGrade() << ", bureaucrat grade " << otherBureau.getGrade() << '\n';
	return (ostream);
}

void	Bureaucrat::signForm(Form &form) const
{
	if (form.getSign())
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because the form is already signed" << '\n';
	else
	{
		try {
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName() << '\n';
		} 
		catch (std::exception &e) {
			std::cout << "\x1B[31m" << this->getName() << " couldn't sign " << form.getName() << " because the bureaucrat grade too low" << "\x1B[0m" << '\n';
		}
	}
}
