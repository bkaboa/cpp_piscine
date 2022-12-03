#include "check.hpp"

Check::Check() {}

Check::~Check() {}

void	Check::checkArg(const int argc, const char **argv)
{
	if (argc != 4)
	{
		std::cout << "invalid number of args" << '\n';
		exit(1);
	}

	if (!argv[1][0] || !argv[2][0] || !argv[3][0])
	{
		std::cout << "arg can't be empty" << '\n';
		exit(1);
	}
}

void	Check::checkFile(const char *fileName)
{
	std::ifstream file;

	file.open(fileName);
	if (file)
	{
		file.close();
		return ;
	}
	std::cout << "no files " << fileName << " exist" << '\n';
	exit(1);
}
