#include "PhoneBook.Class.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	input;

	std::cout << "ADD for new contact, SEARCH for print them and EXIT\n";
	while (std::cin.good() && input != Exit)
	{
		if (input == Add)
			book.addContact(Contact::newContact());
		else if (input == Search)
			book.searhContact();
		std::cout << "> ";
		std::getline(std::cin, input);
	}
	return (0);
}
