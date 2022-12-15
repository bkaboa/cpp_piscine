#ifndef INTERN
# define INTERN

# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class	Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern&);
		AForm *makeForm(std::string&, std::string&);
};

#endif
