#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm:public AForm
{
	private:
		std::string	target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string&);
		ShrubberyCreationForm(const ShrubberyCreationForm&);

		bool				execute(Bureaucrat const & executor) const;
		const std::string	&getTarget(void) const;
		void				setTarget(const std::string &);
		const ShrubberyCreationForm	&operator=(const ShrubberyCreationForm&);
};

#endif
