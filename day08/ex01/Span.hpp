#ifndef SPAN
# define SPAN

# include <exception>
# include <iostream>
# include <list>
# include <cstdlib>
# include <limits>

class Span
{
	private:
		unsigned int N;
		std::list<int> numbers;
		Span();

	public:
		Span(unsigned int N);
		Span(const Span&);
		~Span();

		Span	&operator=(const Span&);

		void			addNumber(int);
		void			addNumbers(int);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		void	print(void);
		void	printSort(void);

		class FullException:public std::exception
		{
			public:
				virtual const char *what() const throw(){
					return ("can't add another number container full");
				}
		};
		class ListException:public std::exception
	{
		public:
			virtual const char *what() const throw(){
				return ("not enough number in list");
			}
	};
};

#endif
