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
		Fixed&operator=(const Fixed&);

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
