#include "Cat.class.hpp"

Cat::Cat():Animal("Cat") {
	std::cout << C_CONSTRUCTOR << '\n';
	this->brain = new Brain;
}

Cat::Cat(const std::string &cat):Animal(cat) {
	std::cout << C_CONSTRUCTOR_PARAM << '\n';
	this->brain = new Brain("think to make meoooooow");
}

Cat::Cat(const Cat &otherCat):Animal() {
	std::cout << C_CONSTRUCTOR_COPY << '\n';
	*this = otherCat;
}

Cat::~Cat() {
	std::cout << C_DESTRUCTOR << '\n';
	delete brain;
}

Cat	&Cat::operator=(const Cat &otherCat)
{
	if (this != &otherCat)
	{
		this->type = otherCat.getType();
		this->brain = new Brain(*otherCat.brain);
	}
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
