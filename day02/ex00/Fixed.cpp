#include "Fixed.hpp"

Fixed&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << '\n';
	this->fixFloat = other.getRawBits();
	return (*this);
}

Fixed::Fixed():fixFloat(0) {
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << '\n';
	*this = fixed;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << '\n';
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << '\n';
	return (fixFloat);
}

void	Fixed::setRawBits(const int raw){
	this->fixFloat = raw;
}
