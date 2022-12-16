#include "Cat.class.hpp"

Cat::Cat() {
	std::cout << C_CONSTRUCTOR << '\n';
	this->type = "Cat";
	this->brain = new Brain;
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

void	Cat::printBrain(void) const {
	brain->printIdeas();
}

void	Cat::set10BrainLine(const std::string &str) const
{
	brain->set10IdeaLine(str);
}
