#ifndef MAIN
# define MAIN

# include <string>
# include <iostream>
# include <typeinfo>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base() {}
};

class	A:public Base {
	public:
		void printA(void) {std::cout << "Identify type A" << '\n';}
};

class	B:public Base {
	public:
		void printB(void) {std::cout << "Identify type B" << '\n';}
};

class	C:public Base {
	public:
		void printC(void) {std::cout << "Identify type C" << '\n';}
};

#endif
