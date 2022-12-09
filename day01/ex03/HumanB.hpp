#ifndef HUMANB
# define HUMANB

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
		HumanB(const std::string);
		HumanB(const std::string name, Weapon weapon);
		~HumanB();

		void	setWeapon(Weapon weapon);
		void	attack(void) const;
};

#endif
