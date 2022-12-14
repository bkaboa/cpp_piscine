#include "Animal.class.hpp"

Animal::Animal() {
	std::cout << A_CONSTRUCTOR << '\n';
}

Animal::~Animal() {
	std::cout << A_DESTRUCTOR << '\n';
}

Animal::Animal(const Animal &otherAnimal) {
	std::cout << A_CONSTRUCTOR_COPY << '\n';
	*this = otherAnimal;
}

const std::string	&Animal::getType(void) const {
	return (this->type);
}

Animal	&Animal::operator=(const Animal &otherAnimal)
{
	if (this != &otherAnimal)
		this->type = otherAnimal.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, const Animal &animal)
{
	ostream << "this is an animal of type " << animal.getType() << '\n';
	return (ostream);
}

void	Animal::setType(const std::string &str) {
	this->type = str;
}
