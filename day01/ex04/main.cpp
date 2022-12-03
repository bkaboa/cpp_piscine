#include <string>
#include <iostream>
#include "application.hpp"
#include "check.hpp"

int main(int argc, char **argv)
{

	Check::checkArg(argc);

	Application	app(argv[1], argv[2], argv[3]);
	Check		valour = Check(app);
	valour.checkFile();
	app.buidNewFile();
	return (0);
}
