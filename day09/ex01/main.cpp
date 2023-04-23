#include "RPN.hpp"

int main(int argc, const char **argv)
{
	if (argc != 2)
	{
		std::cout << "this program must have at least one argument" << '\n';
		return (1);
	}
	try {
		RPN rpnSequence(argv);
		rpnSequence.rpnSquenceStart();
	} catch (const std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return (0);
}
