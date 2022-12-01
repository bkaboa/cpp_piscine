#ifndef PHONEBOOK_CLASS
# define PHONEBOOK_CLASS

# include "Contact.Class.hpp"

class PHONEBOOK
{
	private:
		bool		printSumm(int i);
		void		printContactInfo() const;

	public:
		bool		addContact();
		bool		clear();
};

#endif
