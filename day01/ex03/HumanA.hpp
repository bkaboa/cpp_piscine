#ifndef HUMANA
#define HUMANA

# include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		weapon;

	public:
		~HumanA();
		HumanA(const std::string, const Weapon);

		void	attack(void) const;
};

#endif
