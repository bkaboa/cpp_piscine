#include "Cat.class.hpp"

Cat::Cat() {
	std::cout << C_CONSTRUCTOR << '\n';
	this->type = "Cat";
}

Cat::Cat(const Cat &otherCat):Animal() {
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
