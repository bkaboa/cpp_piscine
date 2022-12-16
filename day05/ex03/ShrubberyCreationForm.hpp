#ifndef SHRUBBERYCREATIONFORM
# define SHRUBBERYCREATIONFORM

# include "Form.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class ShrubberyCreationForm:public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string&);
		ShrubberyCreationForm(const ShrubberyCreationForm&);

		void	execute(Bureaucrat const & executor) const;
		const ShrubberyCreationForm	&operator=(const ShrubberyCreationForm&);
};

#endif
