#include "Fixed.hpp"

Fixed::Fixed():fixFloat(0) {
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed &fixed) {
	std::cout << "Copy constructor called" << '\n';
	*this = fixed;
}

Fixed::Fixed(const int num):fixFloat(num << nBits) {
	std::cout << "Int constructor called" << '\n';
}

Fixed::Fixed(const float floatNum):fixFloat(roundf(floatNum * (float)(1 << nBits))) {
	std::cout << "Float constructor called" << '\n';
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << '\n';
}


int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << '\n';
	return (fixFloat);
}

void	Fixed::setRawBits(const int raw) {
	this->fixFloat = raw;
}


int	Fixed::toInt(void) const {
	return (fixFloat >> nBits);
}

float	Fixed::toFloat(void) const {
	return ((float)fixFloat / (float)(1 << nBits));
}



Fixed&Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << '\n';
	this->fixFloat = other.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed) {
	return (stream << fixed.toFloat());
}
