#include "Dog.class.hpp"

Dog::Dog() {
	std::cout << D_CONSTRUCTOR << '\n';
	this->brain = new Brain("think to make woooof");
	this->type = "Dog";
}

Dog::Dog(const Dog &otherDog):Animal() {
	std::cout << D_CONSTRUCTOR_COPY << '\n';
	*this = otherDog;
}

Dog::~Dog() {
	std::cout << D_DESTRUCTOR << '\n';
	delete brain;
}

Dog	&Dog::operator=(const Dog &otherDog)
{
	if (this != &otherDog)
	{
		this->type = otherDog.getType();
		this->brain = new Brain(*otherDog.brain);
	}
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

void	Dog::printBrain(void) const {
	brain->printIdeas();
}

void	Dog::set10BrainLine(const std::string &str) const
{
	brain->set10IdeaLine(str);
}
