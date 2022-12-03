#ifndef FIXED
# define FIXED

# include <iostream>
#include <ostream>
# include <utility>
# include <cmath>

class Fixed
{
	private:
		static const int	nBits = 8;
		int					fixFloat;

	public:
		bool	operator==(const Fixed&) const;
		bool	operator!=(const Fixed&) const;
		bool	operator<(const Fixed&) const;
		bool	operator>(const Fixed&) const;
		bool	operator>=(const Fixed&) const;
		bool	operator<=(const Fixed&) const;

		static Fixed	max(const Fixed&,const Fixed&);
		static Fixed	max(Fixed&, Fixed&);
		static Fixed	min(const Fixed&, const Fixed&);
		static Fixed	min(Fixed&, Fixed&);

		Fixed	&operator=(const Fixed&);
		Fixed	operator+(const Fixed&) const;
		Fixed	operator-(const Fixed&) const;
		Fixed	operator*(const Fixed&) const;
		Fixed	operator/(const Fixed&) const;
		Fixed	&operator++();
		Fixed	operator++(int);
		Fixed	&operator--();
		Fixed	operator--(int);

		Fixed();
		Fixed(const Fixed &);
		Fixed(const int);
		Fixed(const float);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(const int raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream&, const Fixed &fixed);

#endif
