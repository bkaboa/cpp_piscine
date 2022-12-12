#include "Brain.class.hpp"

Brain::Brain() {
	std::cout << B_CONSTRUCTOR << '\n';
}

Brain::Brain(const std::string str) {
	std::cout << B_CONSTRUCTOR_PARAM << '\n';
	for(int i = 0; i < 100 ; i++)
		this->ideas[i] = str;
}

Brain::~Brain() {
	std::cout << B_DESTRUCTOR << '\n';
}

Brain::Brain(const Brain &brain) {
	*this = brain;
}

Brain	&Brain::operator=(const Brain &otherB){
	for (int i = 0;!otherB.ideas[i].empty();i++)
		this->ideas[i] = otherB.ideas[i];
	return (*this);
}

const std::string	*Brain::getIdeas(void) const{
	return (this->ideas);
}

void	Brain::printIdeas(void) const {
	for (int i = 0; !ideas[i].empty();i++)
		std::cout << ideas[i] << '\n';
}
