#ifndef FORM
# define FORM

# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	name;
		bool				sign;
		const int			execGrade;
		const int			signGrade;
	
	public:
		Form();
		Form(const std::string&,int,int);
		Form(const Form&);
		~Form();

		const std::string	&getName(void) const;
		int					getExecGrade(void) const;
		int					getSignGrade(void) const;
		bool				getSign(void) const;

		void				setIsSigned(void);
		void				beSigned(const Bureaucrat&);

		const Form			&operator=(const Form&);

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
};

std::ostream	&operator<<(std::ostream&, const Form&);

#endif
