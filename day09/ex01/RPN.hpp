#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>
#include <sstream>

# define TOKEN "*/-+"
# define VALIDC "0123456789 */-+"

class RPN
{
public:
	RPN();
	RPN(const char **);
	RPN(const RPN&);
	~RPN();


	RPN &operator=(const RPN&);

	void				setRpnSequence(const char **);
	const std::string	&getRpnSequence() const;

	void rpnSquenceStart();

	class RpnError: virtual public std::exception
	{
		private:
			std::string message;
		public:
			RpnError(std::string msg, int i = 0):message(msg) {}
			virtual ~RpnError() throw() {};
			virtual const char* what() const throw()
			{
				return (message.c_str());
			}
	};

private:
	std::string	rpnSequence;

	std::stack<int> numerals;
};

#endif
