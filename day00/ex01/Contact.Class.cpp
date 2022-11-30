#include "Contact.Class.hpp"
#include <string>

void	printContactVar(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9).append(".");
	else 
		std::cout << std::setfill(' ') << std::setw(10) << str;
}

bool	Contact::clear(void)
{
	this->_Name.clear();
	this->_LastName.clear();
	this->_Nickname.clear();
	this->_Number.clear();
	this->_Secret.clear();
	return (false);
}

bool	Contact::printSumm(int i)
{
	if (_Name.empty())
		return (false);
	std::cout << '|';
	std::cout << std::setfill(' ') << std::setw(10) << i;
	std::cout << '|';
	printContactVar(_Name);
	std::cout << '|';
	printContactVar(_LastName);
	std::cout << '|';
	printContactVar(_Nickname);
	std::cout << '|';
	std::cout << '\n';
	return (true);
}

void	Contact::printContactInfo(void) const
{
	std::cout << "name : " << this->_Name << '\n';
	std::cout << "last name : " << this->_LastName << '\n';
	std::cout << "nickname : " << this->_Nickname << '\n';
	std::cout << "number : " << this->_Number << '\n';
	std::cout << "secrer : " << this->_Secret << '\n';
}

bool	Contact::addContact(void)
{
	std::cout << "enter a new name : ";
	std::getline(std::cin, this->_Name);
	if (this->_Name.empty())
		return (clear());
	std::cout << "enter a new last name : ";
	std::getline(std::cin, this->_LastName);
	if (this->_LastName.empty())
		return (clear());
	std::cout << "enter a new nickname : ";
	std::getline(std::cin, this->_Nickname);
	if (this->_Nickname.empty())
		return (clear());
	std::cout << "enter a new number : ";
	std::getline(std::cin, this->_Number);
	if (this->_Number.empty())
		return (clear());
	std::cout << "enter a new secret : ";
	std::getline(std::cin, this->_Secret);
	if (this->_Secret.empty())
		return (clear());
	return (true);
}
