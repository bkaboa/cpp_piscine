#include "application.hpp"

Application::Application(std::string fileName, std::string oldString, std::string newString): fileName(fileName), oldString(oldString), newString(newString) {}

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
		if (!line.empty())
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
			line.erase(i, oldString.length());
			line.insert(i, newString);
			i += oldString.length();
		}
	}
}
