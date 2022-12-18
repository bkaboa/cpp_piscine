#ifndef ITER
# define ITER

# include <iostream>
# include <string>

template<typename T>
void	iter(T *tab, size_t size, void (*function)(T &element))
{
	for (size_t i = 0; i < size; i++)
		function(tab[i]);
}

template <typename T>
void	printTab(T element)
{
	std::cout << element << '\n';
}

template<typename T>
void	increment(T nbr)
{
	static int i = 1;
	nbr += i;
	i++;
}

#endif
