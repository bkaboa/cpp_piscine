#include "Dog.class.hpp"

Dog::Dog() {
	std::cout << D_CONSTRUCTOR << '\n';
	this->type = "Dog";
}

Dog::Dog(const Dog &otherDog):Animal() {
	std::cout << D_CONSTRUCTOR_COPY << '\n';
	*this = otherDog;
}

Dog::~Dog() {
	std::cout << D_DESTRUCTOR << '\n';
}

Dog	&Dog::operator=(const Dog &otherDog)
{
	this->type = otherDog.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "dog make woooof" << '\n';
}

std::ostream &operator<<(std::ostream &ostream, Dog &cat)
{
	ostream << cat.getType() << '\n';
	return (ostream);
}
