
#ifndef CONTACT_CLASS
# define CONTACT_CLASS

# include <string>
# include <iostream>
# include <iomanip>
# include <features.h>
# include <cstdio>
# include <sstream>
# include <cstdlib>

static const std::string Exit		= "EXIT";
static const std::string Add		= "ADD";
static const std::string Search		= "SEARCH";


class Contact
{
	private:
		std::string _Name;
		std::string _LastName;
		std::string _Nickname;
		std::string _Number;
		std::string _Secret;

	public:
		Contact();
		~Contact();
		bool		printSumm(int i);
		void		printContactInfo() const;
		bool		addContact();
		bool		clear();
};

#endif
