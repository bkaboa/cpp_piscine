#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <exception>
#include <fstream>
#include <string>
#include <iostream>
#include <map>

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

	const std::string	&getStrDataFile() const;

	void	parseExchange(std::string);

	void	setStrDataFile(const char *);

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
	class strDataFileNotSet: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return ("Error: database string file, not setup");
			}
	};

private:
	void	setExchangeMap();

	void	printError(int, std::string);
	void	printExchange(std::tm&, double);

	int		checkData(std::string, int, std::tm&, double&);
	bool	checkValidDate(std::tm&);

	std::string						strDataFile;
	std::map<std::time_t, double>	exchange;
};

#endif // !BITCOINEXCHANGE
