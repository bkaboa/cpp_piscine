#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN(const char **argv) {
	setRpnSequence(argv);
}

RPN::RPN(const RPN &rpn)
{
	*this = rpn;
}

RPN::~RPN()
{
	rpnSequence.clear();
}

const std::string &RPN::getRpnSequence() const {
	return (rpnSequence);
}

void	RPN::setRpnSequence(const char **argv)
{
	int i = 0;
	int j = 0;

	if (!rpnSequence.empty())
		rpnSequence.clear();
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
			rpnSequence.push_back(argv[i][j++]);
		rpnSequence.push_back(' ');
	}
	if (rpnSequence.empty())
	{
		std::cout << "Error: rpn sequence not set" << '\n';
		return ;
	}
}

RPN	&RPN::operator=(const RPN &otherRpn)
{
	if (this != &otherRpn)
		rpnSequence = otherRpn.getRpnSequence();
	return (*this);
}


void	RPN::rpnSquenceStart()
{
	int		number;
	char	*str;

	if (rpnSequence.empty())
	{
		std::cout << "Error: rpn sequence not set" << '\n';
		return ;
	}
	if (rpnSequence.find_first_not_of(VALIDC) != std::string::npos)
	{
		std::cout << "Error: only numerals space and operators like +-/* are valid" << '\n';
		return ;
	}
	for (int i = 0; i < rpnSequence.length(); i++)
	{
		if (std::isalnum(rpnSequence[i]))
		{
			number = std::atoi(rpnSequence.c_str()+i);
			if (number > 9)
			{
				std::cout << "Error: only numerals between 0-9 are valid" << '\n';
				return ;
			}
			numerals.push(number);
		}
		else if (!std::isspace(rpnSequence[i]))
		{
			if (numerals.size() <= 1)
			{
				std::cout << "Error: empty numerals stack, too many operations" << '\n';
				return ;
			}
			number = numerals.top();
			numerals.pop();
			switch (rpnSequence[i]) {
				case '+': numerals.top() += number; break;
				case '-': numerals.top() -= number; break;
				case '*': numerals.top() *= number; break;
				case '/':{
					if (number == 0)
					{
						std::cout << "Error: can't divided by zero" << '\n';
						return ;
					}
					numerals.top() /= number;
					break;
				}
			}
		}
	}
	if (numerals.size() > 1)
	{
		std::cout << "Error: more than one number in stack, miss " << numerals.size() - 1 << " operations" << '\n';
		return ;
	}
	std::cout << numerals.top() << '\n';
}
