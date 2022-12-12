#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << WA_CONSTRUCTOR << '\n';
}

WrongAnimal::WrongAnimal(const std::string &type):_type(type) {
	std::cout << WA_CONSTRUCTOR_PARAM << '\n';
}

WrongAnimal::WrongAnimal(const WrongAnimal &otherW){
	std::cout << WA_CONSTRUCTOR_COPY << '\n';
	*this = otherW;
}

WrongAnimal::~WrongAnimal() {
	std::cout << WA_DESTRUCTOR << '\n';
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &otherW)
{
	this->_type = otherW.getType();
	return (*this);
}

void	WrongAnimal::makesound() const {
	std::cout << "it's zeubi zeubi wrong oooooh" << '\n';
}

const std::string	&WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::setType(const std::string &type) {
	this->_type = type;
}
