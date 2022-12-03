#include "application.hpp"

Application::Application(std::string fileName, std::string newString, std::string oldString): fileName(fileName), newString(newString), oldString(oldString) {}

Application::~Application() {}

std::string	Application::get_fileName(void) const
{
	return(this->fileName);
}

void	Application::buidNewFile(void)
{
	this->newFileName = this->fileName + ".replace";
	std::ifstream	file;
	std::string		line;
	std::ofstream	out(newFileName.c_str());

	file.open(fileName.c_str());
	while (!file.eof())
	{
		getline(file, line);
		replaceString(line);
		out << line << std::endl;
	}
}

void	Application::replaceString(std::string &line)
{
	int	i = 0;

	while (i != -1)
	{
		i = line.find(oldString, i);
		if (i != -1)
		{
			std::cout << i << '\n';
			line.erase(i, oldString.length());
			line.insert(i, newString);
		}
	}
}
