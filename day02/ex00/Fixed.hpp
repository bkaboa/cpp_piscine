#ifndef FIXED
# define FIXED

# include <iostream>
# include <utility>

class Fixed
{
	private:
		static const int	nBits = 8;
		int					fixFloat;

	public:
		Fixed&operator=(const Fixed&);

		Fixed();
		Fixed(const Fixed &);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(const int raw);
};

#endif
