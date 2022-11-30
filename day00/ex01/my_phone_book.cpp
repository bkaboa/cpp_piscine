#include "Contact.Class.hpp"

void	fctAdd(Contact *Contact, int *nContact)
{
	if(*nContact == 8)
		*nContact = 0;
	if (Contact[*nContact].addContact())
		(*nContact)++;
	else if (std::cin.good() == false)
		return ;
	else
		std::cout << "no var can be empty please retry to type ADD\n";
}

void	fctSearch(Contact *Contact)
{
	int			i = 0;
	int			id = 0;
	std::string	input;

	std::cout << "___________________PHONE_BOOK_______________\n";
	std::cout << "|   index  |   name   |last name | nickname |\n";
	while (i < 8 && Contact[i].printSumm(i + 1))
		i++;
	std::cout << "enter the contact index you want : ";
	std::getline(std::cin, input);
	std::stringstream degree(input);
	degree >> id;
	while ((id > i || id <= 0) && std::cin.good())
	{
		std::cout << "enter a valid index : ";
		std::getline(std::cin, input);
		std::stringstream degree(input);
		degree >> id;
	}
	if (id > 0 && (id - 1) < i)
		Contact[id - 1].printContactInfo();
}

int main(void)
{
	std::string	input;
	int			nContact = 0;
	Contact		Contact[8];

	while (std::cin.good() && input != Exit)
	{
		if (input == Add)
			fctAdd(Contact, &nContact);
		if (input == Search)
			fctSearch(Contact);
		std::cout << "> ";
		std::getline(std::cin, input);
	}
	return (0);
}
