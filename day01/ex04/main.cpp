#include <string>
#include <iostream>
#include "application.hpp"
#include "check.hpp"

int main(int argc, char **argv)
{

	Check::checkArg(argc, (const char**)argv);
	Check::checkFile(argv[1]);

	Application	app(argv[1], argv[2], argv[3]);
	app.buidNewFile();
	return (0);
}
