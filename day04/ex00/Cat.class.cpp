#include "Cat.class.hpp"

Cat::Cat():Animal("Cat") {
	std::cout << C_CONSTRUCTOR << '\n';
}

Cat::Cat(const std::string &cat):Animal(cat) {
	std::cout << C_CONSTRUCTOR_PARAM << '\n';
}

Cat::Cat(const Cat &otherCat) {
	std::cout << C_CONSTRUCTOR_COPY << '\n';
	*this = otherCat;
}

Cat::~Cat() {
	std::cout << C_DESTRUCTOR << '\n';
}

Cat	&Cat::operator=(const Cat &otherCat)
{
	this->type = otherCat.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "cat make meoooooow" << '\n';
}

std::ostream &operator<<(std::ostream &ostream, Cat &cat)
{
	ostream << cat.getType() << '\n';
	return (ostream);
}
