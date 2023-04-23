#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "too many argument" << '\n';
		return (1);
	}
	try {
		btc BitcoinExchange;
		BitcoinExchange.parseExchange(argv[1]);
	} catch (const std::exception &e) {
		std::cout << e.what() << '\n';
	}
	return (0);
}
