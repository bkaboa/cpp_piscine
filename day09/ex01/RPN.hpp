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
	RPN(std::string);
	RPN(const RPN&);
	~RPN();

	RPN &operator=(const RPN&);

	std::stack<int>		getNumerals();
	std::string			getRpnSequence();

	void rpnSquenceStart();

private:
	std::string	rpnSequence;

	std::stack<int> numerals;
};

#endif
