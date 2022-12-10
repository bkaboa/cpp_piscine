#include "Dog.class.hpp"

Dog::Dog():Animal("Dog") {
	std::cout << C_CONSTRUCTOR << '\n';
}

Dog::Dog(const std::string &cat):Animal(cat) {
	std::cout << C_CONSTRUCTOR_PARAM << '\n';
}

Dog::Dog(const Dog &otherDog) {
	std::cout << C_CONSTRUCTOR_COPY << '\n';
	*this = otherDog;
}

Dog::~Dog() {
	std::cout << C_DESTRUCTOR << '\n';
}

Dog	&Dog::operator=(const Dog &otherDog)
{
	this->type = otherDog.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "cat make meoooooow" << '\n';
}

std::ostream &operator<<(std::ostream &ostream, Dog &cat)
{
	ostream << cat.getType() << '\n';
	return (ostream);
}
