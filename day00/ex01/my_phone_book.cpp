#include "Contact.Class.hpp"

void	fctAdd(Contact *Contact, int *nContact)
{
	if(*nContact == 8)
		*nContact = 0;
	Contact[*nContact].addContact();
}

void	fctSearch(Contact *Contact)
{
	int			i = 0;
	int			id = 0;
	std::string	input;

	while (i < 8 && Contact[i].printSumm(i))
		i++;
	std::getline(std::cin, input);
	std::stringstream degree(input);
	degree >> id;
	while (id > i && id <= 0)
	{
		std::cout << "enter a valid index:\n";
		std::getline(std::cin, input);
		std::stringstream degree(input);
		degree >> id;
	}
	Contact[id].printContactInfo();
}

int main(void)
{
	std::string	input;
	int			nContact = 0;
	Contact		Contact[8];

	while (std::cin.good())
	{
		if (input == Add)
			fctAdd(Contact, &nContact);
		if (input == Search)
			fctSearch(Contact);
		std::cout << "> ";
		std::getline(std::cin, input);
		std::cout << '\n';
	}
	return (0);
}
