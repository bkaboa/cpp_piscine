#include "Harl.hpp"

void	Harl::complain(std::string level)
{
	std::string	str[] = {"DEBUG", "ERROR", "INFO", "WARNING"};
	void (Harl::*ptr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for(int i = 0;i < 4; i++)
		if (level == str[i])
			this->*ptr[i](void);
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
