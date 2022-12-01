#ifndef WEAPON
# define WEAPON

# include <string>
# include <iostream>

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon();
		Weapon(std::string);
		~Weapon();

		void		setType(const std::string type);
		std::string	getType(void) const;
};

#endif
