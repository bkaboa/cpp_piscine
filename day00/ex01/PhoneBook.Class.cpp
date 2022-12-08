#include "PhoneBook.Class.hpp"

PhoneBook::PhoneBook():_nEntries(0) {}

PhoneBook::~PhoneBook() {}

void	printContactVar(const std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9).append(".");
	else 
		std::cout << std::setfill(' ') << std::setw(10) << str;
}

void	PhoneBook::printPhoneBook(void) const
{
	Contact		contact;

	std::cout << "___________________PHONE_BOOK_______________\n";
	std::cout << "|   index  |   name   |last name | nickname |\n";
	for(int i = 0; i < 8; i++)
	{
		contact = this->_data[i];
		std::cout << '|';
		std::cout << std::setfill(' ') << std::setw(10) << i + 1;
		std::cout << '|';
		printContactVar(contact.getName());
		std::cout << '|';
		printContactVar(contact.getLastName());
		std::cout << '|';
		printContactVar(contact.getNickname());
		std::cout << '|';
		std::cout << '\n';
	}
}

void	PhoneBook::printContact(int index) const
{
	std::cout << "name : " << _data[index].getName() << '\n';
	std::cout << "last name : " << _data[index].getLastName() << '\n';
	std::cout << "nickname : " << _data[index].getNickname() << '\n';
	std::cout << "number : " << _data[index].getNumber() << '\n';
	std::cout << "secret : " << _data[index].getSecret() << '\n';
}

void	PhoneBook::searhContact(void) const
{
	int			index = 0;
	std::string input;

	if (_nEntries == 0)
	{
		std::cout << "no contact for the moment\n";
		return ;
	}
	printPhoneBook();
	std::cout << "enter the contact index you want print : ";
	std::getline(std::cin , input);
	index = input[0] - 48;
	while ((index <= 0 || index > 8 || index > _nEntries || input.size() > 1) && std::cin.good())
	{
		std::cout << "enter a valid index : ";
		std::getline(std::cin, input);
		index = input[0] - 48;
	}
	if (std::cin.good())
		printContact(index - 1);
}

void	PhoneBook::addContact(Contact newContact)
{
	this->_data[_nEntries % 8] = newContact;
	this->_nEntries++;
}
