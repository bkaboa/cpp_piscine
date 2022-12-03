#include "check.hpp"

Check::Check(Application &valour):valour(valour) {}

Check::~Check() {}

void	Check::checkArg(const int argc)
{
	if (argc != 4)
	{
		std::cout << "invalid number of args" << '\n';
		exit(1);
	}
}

void	Check::checkFile(void) const
{
	std::ifstream file;

	file.open(valour.get_fileName());
	if (file)
	{
		file.close();
		return ;
	}
	std::cout << "no files " << valour.get_fileName() << " exist" << '\n';
	exit(1);
}
