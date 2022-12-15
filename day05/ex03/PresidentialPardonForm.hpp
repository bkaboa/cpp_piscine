#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

# include "Form.hpp"

class PresidentialPardonForm:public AForm
{
	private:
		std::string	target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string&);
		PresidentialPardonForm(const PresidentialPardonForm&);

		bool	execute(Bureaucrat const & executor) const;
		const std::string	&getTarget(void) const;
		void				setTarget(const std::string &);
		const PresidentialPardonForm	&operator=(const PresidentialPardonForm&);
};

#endif
