#include "WrongCat.class.hpp"
#include "Animal.class.hpp"
#include "WrongAnimal.class.hpp"

WrongCat::WrongCat() {
	std::cout << WC_CONSTRUCTOR << '\n';
}

WrongCat::WrongCat(const std::string &type):WrongAnimal(type) {
	std::cout << WC_CONSTRUCTOR_PARAM << '\n';
}

WrongCat::WrongCat(const WrongCat &otherWC):WrongAnimal() {
	std::cout << WC_CONSTRUCTOR_COPY << '\n';
	*this = otherWC;
}

WrongCat::~WrongCat() {
	std::cout << WC_DESTRUCTOR << '\n';
}

WrongCat	&WrongCat::operator=(const WrongCat &otherWC)
{
	this->_type = otherWC.getType();
	return(*this);
}
