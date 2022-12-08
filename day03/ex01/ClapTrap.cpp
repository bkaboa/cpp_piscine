#include "ClapTrap.hpp"
#include <string>

ClapTrap::~ClapTrap(void){
	std::cout << DESTRUCTOR << '\n';
}

ClapTrap::ClapTrap():_name("\0"), _hit(10), _energy(10), _attack(0){
	std::cout << CONSTRUCTOR << '\n';
}

ClapTrap::ClapTrap(const std::string Name):_name(Name), _hit(10), _energy(10), _attack(0) {
	std::cout << CONSTRUCTOR << '\n';
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << COPY_CONSTRUCTOR << '\n';
	*this = clapTrap;
}

ClapTrap::ClapTrap(std::string name, int hit, int energy, int attack) {
	_name = name;
	_hit = hit;
	_energy = energy;
	_attack = attack;
}

void	ClapTrap::setName(const std::string str) {
	_name = str;
}

void	ClapTrap::setHit(const int hit) {
	_hit = hit;
}

void	ClapTrap::setenergy(const int energy) {
	_energy = energy;
}

void	ClapTrap::setattack(const int attack) {
	_attack = attack;
}

std::string ClapTrap::getName(void) const {
	return (_name);
}

int	ClapTrap::getHit(void) const {
	return (_hit);
}

int	ClapTrap::getAttack(void) const {
	return (_attack);
}

int	ClapTrap::getEnergy(void) const {
	return (_energy);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->_energy > 0 && this->_hit > 0)
	{
		this->_energy = 1;
		std::cout << this->_name << " attack " << target << '\n';
		return ;
	}
	if (this->_energy <= 0)
		std::cout << this->_name << "out of energy" << '\n';
	else
		std::cout << this->_name << " already dead" << '\n';
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hit > 0)
	{
		this->_hit -= amount;
		std::cout << this->_name << " take " << amount << " damage" << '\n';
		return ;
	}
	std::cout << this->_name << " already dead" << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energy > 0 && this->_hit > 0)
	{
		this->_hit += amount;
		this->_energy -= 1;
		std::cout << this->_name << " repaired " << amount << " Hit point" << '\n';
		return ;
	}
	if (this->_energy <= 0)
		std::cout << this->_name << " out of energy" << '\n';
	else
		std::cout << this->_name << " already dead" << '\n';
}

ClapTrap &ClapTrap::operator=(const ClapTrap & other)
{
	std::cout << ASSIGNEMENT << '\n';
	this->_name = other.getName();
	this->_hit = other.getHit();
	this->_energy = other.getEnergy();
	this->_attack = other.getAttack();
	return (*this);
}

std::ostream &operator<<(std::ostream &ostream, const ClapTrap &clapTrap)
{
	ostream << "name : " << clapTrap.getName() << '\n';
	ostream << "hit point : " << clapTrap.getHit() << '\n';
	ostream << "energy point : " << clapTrap.getEnergy() << '\n';
	ostream << "attack point : " << clapTrap.getAttack() << '\n';
	return (ostream);
}
