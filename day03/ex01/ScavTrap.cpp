#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << SCAV_CONSTRUCTOR << '\n';
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(const std::string &name) {
	std::cout << SCAV_CONSTRUCTOR_PARAM << '\n';
	this->_name = name;
	this->_hit = 100;
	this->_energy = 50;
	this->_attack = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scav):ClapTrap() {
	std::cout << SCAV_COPY_CONSTRUCTOR << '\n';
	*this = scav;
}

ScavTrap::~ScavTrap() {
	std::cout << SCAV_DESTRUCTOR << '\n';
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energy > 0 && _hit > 0)
	{
		std::cout << _name << " scavtrap attack " << target << '\n';
		std::cout << "make " << _attack << " damage" << '\n';
	}
	if (_energy <= 0 && _hit > 0)
		std::cout << _name << " out of energy" << '\n';
	else
		std::cout << _name << " already dead" << '\n';
}

ScavTrap &::ScavTrap::operator=(const ScavTrap &otherScav)
{
	std::cout << SCAV_ASSIGNEMENT << '\n';
	this->_name = otherScav.getName();
	this->_energy = otherScav.getEnergy();
	this->_hit = otherScav.getHit();
	this->_attack = otherScav.getAttack();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, const ScavTrap &scavtrap)
{
	ostream << "scavtrap name : " << scavtrap.getName() << '\n';
	ostream << "scavtrap hit point : " << scavtrap.getHit() << '\n';
	ostream << "scavtrap energy point : " << scavtrap.getEnergy() << '\n';
	ostream << "scavtrap attack point : " << scavtrap.getAttack() << '\n';
	return (ostream);
}

void	ScavTrap::guardGate(void)
{
	std::cout << "scavtrap " << _name << " become gate keeper" << '\n';
}
