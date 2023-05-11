#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const char **argv) {
	setRpnSequence(argv);
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN::~RPN() {}

const std::string &RPN::getRpnSequence() const {
	return (rpnSequence);
}

void	RPN::setRpnSequence(const char **argv)
{
	rpnSequence = argv[1];
	if (rpnSequence.empty())
		throw RpnError("Error : rpn sequence not set");
}

RPN	&RPN::operator=(const RPN &otherRpn)
{
	if (this != &otherRpn)
		rpnSequence = otherRpn.getRpnSequence();
	return (*this);
}


void	RPN::rpnSquenceStart()
{
	float		number;

	if (rpnSequence.find_first_not_of(VALIDC) != std::string::npos)
		throw RpnError("Error: only numerals space and operators like +-/* are valid");
	for (unsigned long i = 0; i < rpnSequence.length(); i++)
	{
		if (std::isalnum(rpnSequence[i]))
		{
			number = std::atoi(rpnSequence.c_str()+i);
			if (number > 9)
				throw RpnError("Error: only numerals between 0-9 are valid");
			numerals.push(number);
		}
		else if (!std::isspace(rpnSequence[i]))
		{
			if (numerals.size() <= 1)
				throw RpnError("Error: empty numerals stack, too many operations");
			number = numerals.top();
			numerals.pop();
			switch (rpnSequence[i]) {
				case '+': numerals.top() += number; break;
				case '-': numerals.top() -= number; break;
				case '*': numerals.top() *= number; break;
				case '/':{
					if (number == 0)
						throw RpnError("Error: can't divided by zero");
					numerals.top() /= number;
					break;
				}
			}
		}
	}
	if (numerals.empty())
		throw RpnError("Error : rpn sequence not set");
	if (numerals.size() > 1)
	{
		std::stringstream out;
		out << numerals.size() -1;
		throw RpnError("Error: more than one number remains in stack, miss " + out.str() + " operations");
	}
	std::cout << numerals.top() << '\n';
}
