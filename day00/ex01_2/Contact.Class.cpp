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

void	setVar(std::string message, std::string *contactVar)
{
	while (contactVar->empty() && std::cin.good())
	{
		std::cout << message;
		std::getline(std::cin, *contactVar);
		if (contactVar->empty() && std::cin.good())
			std::cout << "please incert something can't be empty ";
	}
}

Contact	Contact::newContact(void)
{
	Contact contact;

	setVar("enter new name : ", &contact._Name);
	setVar("enter new last name : ", &contact._LastName);
	setVar("enter new nickname : ", &contact._Nickname);
	setVar("enter new number : ", &contact._Number);
	setVar("enter new secret : ", &contact._Secret);
	return (contact);
}
