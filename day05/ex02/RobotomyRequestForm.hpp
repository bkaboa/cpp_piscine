#ifndef ROBOTMYREQUESTFORM
# define ROBOTMYREQUESTFORM

# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm:public AForm
{
	private:
		std::string	target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string&);
		RobotomyRequestForm(const RobotomyRequestForm&);

		bool	execute(Bureaucrat const & executor) const;
		const std::string	&getTarget(void) const;
		void				setTarget(const std::string &);
		const RobotomyRequestForm &operator=(const RobotomyRequestForm&);
};

#endif
