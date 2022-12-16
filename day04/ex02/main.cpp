#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"
#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	Animal	*truc[4];
	//Animal	Animal;
	for (int i = 0;i < 4;i++)
	{
		if (i % 2 == 0)
			truc[i] = new Dog;
		else 
			truc[i] = new Cat;
	}
	for (int i = 0;i < 4;i++)
		delete truc[i];
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	Dog	boogy;
	Dog	trol(boogy);
	Dog	*poupou = new Dog(boogy);
	std::cout << boogy << '\n';
	std::cout << trol << '\n';
	std::cout << *poupou << '\n';
	delete poupou;
}
