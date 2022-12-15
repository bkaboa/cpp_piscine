#ifndef FORM
# define FORM

# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			execGrade;
		const int			signGrade;
	
	public:
		AForm();
		AForm(const std::string&,int,int);
		AForm(const AForm&);
		virtual ~AForm();

		const std::string	&getName(void) const;
		int					getExecGrade(void) const;
		int					getSignGrade(void) const;
		bool				getSign(void) const;

		void				setIsSigned(bool);

		void				beSigned(const Bureaucrat&);
		bool				virtual execute(Bureaucrat const &) const = 0;

		const AForm			&operator=(const AForm&);

		// Class
		class GradeTooHightException:public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return ("Exception grade too hight");
			}
	};
		class GradeTooLowException:public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return ("Exception grade too low");
			}
	};
		class GradeTooHightExceptionExecution:public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return ("bureaucrat grade too low too execute this form");
			}
	};
		class FormNotSigned:public std::exception
	{
		public:
			virtual const char *what() const throw() {
				return ("form is not signed");
			}
	};
};

std::ostream	&operator<<(std::ostream&, const AForm&);

#endif
