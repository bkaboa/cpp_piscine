#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <exception>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <limits>
#include <stdexcept>

# define DATABASE 1
# define EXCHANGE 2

class btc
{
public:
	btc();
	btc(std::string);
	btc(const btc&);
	~btc();

	btc	&operator=(const btc&);

	std::string	getDataBtc() const;
	std::map<std::time_t, double> getExchange() const;

	void	initmap(std::string = "data.csv");
	void	parseExchange(std::string);

	class dataBaseCorrupted: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("error : database corrupted");
			}
	};

	class fileError: public std::ios_base::failure
	{
		public:
			fileError(const std::string &message) : std::ios_base::failure(message){}
	};

private:
	void	printExchange(std::tm&, double);
	int		checkData(std::string, int, std::tm&, double&);
	bool	checkValidDate(std::tm&);
	void	printError(int, std::string);
	std::string				dataStrBtc;
	std::map<std::time_t, double>	exchange;
};

#endif // !BITCOINEXCHANGE
