#ifndef ROBOTMYREQUESTFORM
# define ROBOTMYREQUESTFORM

# include <ctime>
# include "Form.hpp"

class RobotomyRequestForm:public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string&);
		RobotomyRequestForm(const RobotomyRequestForm&);

		void	execute(Bureaucrat const & executor) const;
		const RobotomyRequestForm &operator=(const RobotomyRequestForm&);
};

#endif
