#include <cctype>
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>

void	printChar(double convertNumber, const std::string &str)
{
	std::cout << str << " >> ";
	if ((convertNumber == 0 && str.length() > 1)
		|| convertNumber < std::numeric_limits<unsigned char>::min()
		|| convertNumber > std::numeric_limits<char>::max()
		|| str == "nan")
		std::cout << "char: impossible to print" << '\n';
	else if (str.length() == 1 && !std::isdigit(str[0]))
		std::cout << "char: " << str << '\n';
	else if (convertNumber < 32 || convertNumber > 126)
		std::cout << "char: non printable" << '\n';
	else
		std::cout << "char: " << static_cast<char>(convertNumber) << '\n';
}

void	printInt(double convertNumber, const std::string &str)
{
	std::cout << str << " >> ";
	if ((str == "nan")
			|| convertNumber < std::numeric_limits<int>::min()
			|| convertNumber > std::numeric_limits<int>::max())
		std::cout << "int: impossible to print" << '\n';
	else
		std::cout << "int:" << static_cast<int>(convertNumber) << '\n';
}

void	printFloat(double convertNumber, const std::string &str)
{
	std::cout << str << " >> ";
	if (float(convertNumber - static_cast<float>(convertNumber)) == 0)
		std::cout << "float: " << static_cast<float>(convertNumber) << ".0f" << '\n';
	else
		std::cout << "float: " << static_cast<float>(convertNumber) << "f" << '\n';
}

void	printDouble(double convertNumber, const std::string &str)
{
	std::cout << str << " >> ";
	if (double(convertNumber - static_cast<int>(convertNumber)) == 0)
		std::cout << "double: " << convertNumber << ".0" << '\n';
	else
		std::cout << "double: " << convertNumber << '\n';
}

void	printConverter(const std::string &str)
{
	double	convertNumber = atof(str.c_str());

	void	(*func[])(double, const std::string&) = {printChar, printInt, printFloat, printDouble};
	for (int i = 0; i < 4; i++) {
		(*func[i])(convertNumber, str);
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "need just 1 argument" << '\n';
		return (1);
	}
		printConverter(av[1]);
	return (0);
}
