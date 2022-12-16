#ifndef BUREAUCRUT
# define BUREAUCRUT

# include <bits/types/FILE.h>
# include <string>
# include <iostream>
# include <exception>
# include <cstdlib>
# include "Form.hpp"

class AForm;

class	Bureaucrat
{
	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string &, int);
		Bureaucrat(const Bureaucrat&);
		

		class TooHighException :public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade too hight Exception");
			}
	};

		class TooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("grade too low Exception");
			}
	};

		void				upgrade(void);
		void				downgrade(void);
		Bureaucrat			&operator=(const Bureaucrat&);
		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				signForm(AForm &) const;
		void				executeForm(AForm const & form);
};

std::ostream	&operator<<(std::ostream&, const Bureaucrat&);

#endif
