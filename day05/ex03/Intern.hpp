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
		AForm *makeForm(const std::string&, const std::string&);

		class	InternMakeException:public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return ("this Intern can't create that Form Exception");
			}
	};
};

#endif
