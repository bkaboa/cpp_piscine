#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << FRAG_CONSTRUCTOR << '\n';
}

FragTrap::FragTrap(const std::string &name) {
	std::cout << FRAG_CONSTRUCTOR_PARAM << '\n';
	this->_name = name;
	this->_hit = 100;
	this->_energy = 100;
	this->_attack = 30;
}

FragTrap::FragTrap(const FragTrap &frag) : ClapTrap() {
	std::cout << FRAG_COPY_CONSTRUCTOR << '\n';
	*this = frag;
}

FragTrap::~FragTrap() {
	std::cout << FRAG_DESTRUCTOR << '\n';
}

FragTrap	&FragTrap::operator=(const FragTrap &otherFrag)
{
	this->_name = otherFrag.getName();
	this->_hit = otherFrag.getHit();
	this->_energy = otherFrag.getEnergy();
	this->_attack = otherFrag.getAttack();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, const FragTrap &frag)
{
	ostream << "fragtrap name : " << frag.getName() << '\n';
	ostream << "fragtrap hit point : " << frag.getHit() << '\n';
	ostream << "fragtrap energy point : " << frag.getEnergy() << '\n';
	ostream << "fragtrap attack point : " << frag.getAttack() << '\n';
	return (ostream);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << _name << " ask you to make high five" << '\n';
	std::cout << "say yes if you want, say no if you won't" << '\n';
	std::cout << "you say yes " << _name << " want to make love with you" << '\n';
}
