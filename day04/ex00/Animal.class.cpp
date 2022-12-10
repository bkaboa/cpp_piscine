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

Animal::Animal(const std::string &type):type(type) {
	std::cout << A_CONSTRUCTOR_PARAM << '\n';
}

std::string	Animal::getType(void) const {
	return (type);
}

Animal	&Animal::operator=(const Animal &otherAnimal)
{
	if (this != &otherAnimal)
		this->type = otherAnimal.getType();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostream, const Animal &animal)
{
	ostream << "this is an animal" << '\n';
	return (ostream);
}
