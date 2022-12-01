#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

#include "Contact.Class.hpp"

class	PhoneBook
{
	private:
		Contact	_Data[8];
		int		_nContact;
		int		_Entries;
		void	printPhoneBook(void)const;
		void	printContact(int index) const;

	public:
		PhoneBook();
		~PhoneBook();

		void	addContact(Contact newContact);
		void	searhContact(void) const;
};

#endif
