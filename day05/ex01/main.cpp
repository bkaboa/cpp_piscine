#include "Form.hpp"

int	main(void)
{
	Bureaucrat bla("truc", 150);
	Bureaucrat bla2("truc2", 1);
	//Bureaucrat bla3("truc3", 151);
	//Bureaucrat bla4("truc4", 0);
	//Form	truc2("bka", 152, 54);
	Form	truc("bka", 45, 45);
	bla.signForm(truc);
	bla2.signForm(truc);
	bla2.signForm(truc);
}
