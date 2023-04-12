#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>
#include <iostream>

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

	class emptyArgs: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error : no args");
			}
	};

private:
	std::string	rpnSequence;

	std::stack<int> numerals;
};

#endif
