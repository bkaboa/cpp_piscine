#include "ClapTrap.hpp"

ClapTrap::~ClapTrap(void){
	std::cout << DESTRUCTOR << '\n';
}

ClapTrap::ClapTrap():Hit(10), Energy(10), Attack(0){
	std::cout << CONSTRUCTOR << '\n';
}

ClapTrap::ClapTrap(const std::string Name):Name(Name), Hit(10), Energy(10), Attack(0) {
	std::cout << CONSTRUCTOR << '\n';
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << COPY_CONSTRUCTOR << '\n';
	*this = clapTrap;
}

void	ClapTrap::setName(const std::string &str)
{
	this->Name = str;
}

const std::string &ClapTrap::getName(void) const {
	return (Name);
}

int	ClapTrap::getHit(void) const {
	return (Hit);
}

int	ClapTrap::getAttack(void) const {
	return (Attack);
}

int	ClapTrap::getEnergy(void) const {
	return (Energy);
}

void	ClapTrap::attack(const std::string &target) {
	if (this->Energy > 0 && this->Hit > 0)
	{
		this->Energy -= 1;
		std::cout << this->Name << " attack " << target << '\n';
		return ;
	}
	if (this->Energy <= 0)
		std::cout << this->Name << "out of energy" << '\n';
	else
		std::cout << this->Name << " already dead" << '\n';
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->Hit > 0)
	{
		this->Hit -= amount;
		std::cout << this->Name << " take " << amount << " damage" << '\n';
		return ;
	}
	std::cout << this->Name << " already dead" << '\n';
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->Energy > 0 && this->Hit > 0)
	{
		this->Hit += amount;
		this->Energy -= 1;
		std::cout << this->Name << " repaired " << amount << " Hit point" << '\n';
		return ;
	}
	if (this->Energy <= 0)
		std::cout << this->Name << " out of energy" << '\n';
	else
		std::cout << this->Name << " already dead" << '\n';
}

ClapTrap &ClapTrap::operator=(const ClapTrap & other)
{
	std::cout << ASSIGNEMENT << '\n';
	this->Name = other.getName();
	this->Hit = other.getHit();
	this->Energy = other.getEnergy();
	this->Attack = other.getAttack();
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
