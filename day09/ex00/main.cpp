#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "too many argument" << '\n';
		return (1);
	}
	btc BitcoinExchange;

	BitcoinExchange.parseExchange(argv[1]);
	return (0);
}
