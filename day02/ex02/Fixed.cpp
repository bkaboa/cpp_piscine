#include "Fixed.hpp"

Fixed::Fixed():fixFloat(0) {
}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed::Fixed(const int num):fixFloat(num << nBits) {
}

Fixed::Fixed(const float floatNum):fixFloat(roundf(floatNum * (float)(1 << nBits))) {
}

Fixed::~Fixed() {
}


int	Fixed::getRawBits(void) const {
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





/*
 *				arithmetic operator
*/
Fixed&Fixed::operator=(const Fixed &other)
{
	this->fixFloat = other.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &other) const {
	return (toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const {
	return (toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const {
	return (toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const {
	return (toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++() {
	this->fixFloat += 1;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	++(this->fixFloat);
	return (temp);
}

Fixed	&Fixed::operator--() {
	this->fixFloat -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp = *this;
	--(this->fixFloat);
	return (temp);
}

/*
 *				stream operator
*/
std::ostream &operator<<(std::ostream &stream, const Fixed &fixed) {
	return (stream << fixed.toFloat());
}

/*
 *				comparaison operator
*/
bool	Fixed::operator==(const Fixed &other) const {
	return (fixFloat == other.fixFloat);
}

bool	Fixed::operator!=(const Fixed &other) const {
	return (fixFloat != other.fixFloat);
}

bool	Fixed::operator<(const Fixed &other) const {
	return (fixFloat < other.fixFloat);
}

bool	Fixed::operator>(const Fixed &other) const {
	return (fixFloat > other.fixFloat);
}

bool	Fixed::operator<=(const Fixed &other) const {
	return (fixFloat <= other.fixFloat);
}

bool	Fixed::operator>=(const Fixed &other) const {
	return (fixFloat >= other.fixFloat);
}

Fixed	Fixed::max(const Fixed &first, const Fixed &second) {
	return (first > second ? first : second);
}

Fixed	Fixed::max(Fixed &first, Fixed &second) {
	return (first > second ? first : second);
}

Fixed	Fixed::min(const Fixed &first, const Fixed &second) {
	return (first > second ? second : first);
}

Fixed	Fixed::min(Fixed &first, Fixed &second) {
	return (first > second ? second : first);
}
