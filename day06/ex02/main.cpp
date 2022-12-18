#include "main.hpp"

Base * generate(void)
{
	switch (rand() % 3) {
		case 0:
			std::cout << "type A generated" << '\n';
			return (new A);
		case 1:
			std::cout << "type B generated" << '\n';
			return (new B);
		default:
			std::cout << "type C generated" << '\n';
			return (new C);
	}
}

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c= dynamic_cast<C*>(p);

	if (a)
		a->printA();
	else if (b)
		b->printB();
	else if (c)
		c->printC();
	else 
		std::cout << "unknown type" << '\n';
}

void identify(Base& p)
{
	try {
		A	&a = dynamic_cast<A&>(p);
		a.printA();
		return ;
	} catch (...) {}

	try {
		B	&b = dynamic_cast<B&>(p);
		b.printB();
		return ;
	} catch (...) {}

	try {
		C	&c = dynamic_cast<C&>(p);
		c.printC();
		return ;
	} catch (std::bad_cast &bc) {}

	std::cout << "unknown type" << '\n';
}

int main(void)
{
	Base	*base;

	srand(time(NULL));
	base = generate();
	identify(base);
	identify(*base);
	return (0);
}
