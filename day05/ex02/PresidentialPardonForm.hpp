#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

# include "Form.hpp"

class PresidentialPardonForm:public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string&);
		PresidentialPardonForm(const PresidentialPardonForm&);

		void	execute(Bureaucrat const & executor) const;
		const PresidentialPardonForm	&operator=(const PresidentialPardonForm&);
};

#endif
