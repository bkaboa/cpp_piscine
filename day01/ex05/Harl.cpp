#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::complain(std::string level)
{
	std::string	str[] = {"DEBUG", "ERROR", "INFO", "WARNING"};
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::error, &Harl::info, &Harl::warning};
	for(int i = 0;i < 4; i++)
	{
		if (level == str[i])
		{
			(this->*ptr[i])();
			return ;
		}
	}
	std::cout << "DEBUG ERROR INFO WARNING are expected" << '\n';
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
