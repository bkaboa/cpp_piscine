#ifndef HUMANA
# define HUMANA

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		weapon;
		std::string	name;

	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();

		void	attack(void) const;
};

#endif
