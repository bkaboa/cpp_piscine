#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	btc BitcoinExchange;

	if (argc != 2)
	{
		std::cout << "Error: could not open file." << '\n';
		return (1);
	}
	try {
		BitcoinExchange.initmap();
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
		return (1);
	}
	try {
		BitcoinExchange.parseExchange(argv[1]);
	} catch (std::exception &e) {
		std::cout << e.what() << '\n';
		return (1);
	}
}
