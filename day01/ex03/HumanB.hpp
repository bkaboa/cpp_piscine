#ifndef HUMANB
# define HUMANB

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
		HumanB(std::string name);
		HumanB(std::string name, Weapon weapon);
		~HumanB();

		void	setWeapon(Weapon weapon);
		void	attack(void) const;
};

#endif
