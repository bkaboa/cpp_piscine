#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain(std::string level)
{
	int		i = indexReturn(level);

	void (Harl::*ptr[4])(void) = {&Harl::info, &Harl::debug, &Harl::warning, &Harl::error};

	switch (i) {
		case 0: 
			(this->*ptr[i++])();
		case 1: 
			(this->*ptr[i++])();
		case 2: 
			(this->*ptr[i++])();
		case 3: 
			(this->*ptr[i++])();
			break;
		default: std::cout << "DEBUG ERROR INFO WARNING are expected" << '\n';
				 break;
	}
}

void	Harl::debug( void ) {
	std::cout << DEBUG << '\n';
}

void	Harl::info( void ) {
	std::cout << INFO << '\n';
}

void	Harl::warning( void){
	std::cout << WARNING << '\n';
}

void	Harl::error( void ) {
	std::cout << ERROR << '\n';
}

int	indexReturn(std::string level)
{
	int	i;
	std::string	str[] = {"DEBUG", "ERROR", "INFO", "WARNING"};

	for (i = 0; i < 4 && str[i] != level; i++);
	return (i);
}
