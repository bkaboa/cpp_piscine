#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: one argument is needed between \"\" " << '\n';
	}
	RPN truc(argv[1]);
	truc.rpnSquenceStart();
	return (0);
}
