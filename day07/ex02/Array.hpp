#ifndef ARRAY
# define ARRAY

# include <exception>
# include <iostream>
# include <string>

template<typename T>
class Array
{
	private:
		unsigned int	lenght;
		T				*contents;

	public:
		Array():lenght(0), contents(0) {}

		Array(unsigned int lenght):lenght(lenght), contents(new T[lenght]) {}

		Array(const T *contents, unsigned int lenght):lenght(lenght), contents(new T[lenght]) {
			for(unsigned int i = 0; i < lenght; i++)
				this->contents[i] = contents[i];
		}

		Array(const Array &other):lenght(other.lenght), contents(new T[other.lenght]) {
			for(unsigned int i = 0; i < lenght; i++)
				this->contents[i] = other.contents[i];
		}

		~Array(){
			if (this->contents)
				delete [] this->contents;
		}

		Array	&operator=(const Array &other){
			if (this->contents)
				delete [] contents;
			this->contents = new T[other.lenght];
			this->lenght = other.getLenght();
			for (unsigned int i = 0; i < lenght; i++)
				this->contents[i] = other.contents[i];
			return (*this);
		}

		unsigned int	getLenght(void) const{
			return (lenght);
		}

		const T &operator[](int idx) const {
			if (static_cast<unsigned int>(idx) > lenght)
				throw indexOutOfArray();
			return (contents[idx]);
		}

		T &operator[](int idx) {
			if (static_cast<unsigned int>(idx) > lenght)
				throw indexOutOfArray();
			return (contents[idx]);
		}

		void	printArray(void) const
		{
			for (unsigned int i = 0; i < lenght; i++)
				std::cout << contents[i] << '\n';
		}

		class indexOutOfArray:public std::exception
	{
		public:
			virtual const char *what() const throw(){
				return ("index out of array");
			}
	};
};

#endif
