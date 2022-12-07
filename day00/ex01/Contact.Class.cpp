#include "Contact.Class.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string	Contact::getName(void) const
{
	return(this->_Name);
}

std::string Contact::getLastName(void) const
{
	return (this->_LastName);
}

std::string Contact::getNickname(void) const
{
	return (this->_Nickname);
}

std::string Contact::getNumber(void) const
{
	return (this->_Number);
}

std::string Contact::getSecret(void) const
{
	return (this->_Secret);
}

bool	ftIsExtendAscii(std::string isEx)
{
	int	i = -1;
	while (isEx[++i])
	{
		if ((unsigned char)isEx[i] > 127)
			return (false);
	}
	return (true);
}

void	setVar(std::string message, std::string *contactVar)
{
	bool	extendAscci = false;

	while (contactVar->empty() && std::cin.good() && extendAscci == false)
	{
		std::cout << message;
		std::getline(std::cin, *contactVar);
		extendAscci = ftIsExtendAscii(*contactVar);
		if (contactVar->empty() && std::cin.good())
			std::cout << "the contact var can't be empty ";
		if(extendAscci == false)
			std::cout << "phoneBook can't take extend ascii ";
	}
}

bool	ftIsNum(std::string str)
{
	int	i = -1;

	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
	}
	return (true);
}

void	setNum(std::string message, std::string *numVar)
{

	bool	isNum = false;

	while (numVar->empty() && std::cin.good() && isNum == false)
	{
		std::cout << message;
		std::getline(std::cin, *numVar);
		isNum = ftIsNum(*numVar);
		if (isNum == false)
			std::cout << "only number are expected in num var " << '\n';
		if (numVar->empty() && std::cin.good())
			std::cout << "the contact var can't be empty ";
	}
}


Contact	Contact::newContact(void)
{
	Contact contact;

	setVar("enter new name : ", &contact._Name);
	setVar("enter new last name : ", &contact._LastName);
	setVar("enter new nickname : ", &contact._Nickname);
	setNum("enter new number : ", &contact._Number);
	setVar("enter new secret : ", &contact._Secret);
	return (contact);
}
