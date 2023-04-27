#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <exception>
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>

# define DATABASE 1
# define EXCHANGE 2

typedef struct data{
	std::string date;
	double price;
} sData;

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

	class exceptionError : virtual public std::exception
	{
		private:
			std::string message;
		public:
			exceptionError(const std::string &msg):message(msg) {}
			virtual ~exceptionError() throw() {};
			virtual const char *what() const throw()
			{
				return (message.c_str());
			}
	};

private:
	void	setExchangeMap();

	void	printError(int, std::string);
	void	printExchange(double, std::string);

	int		checkData(std::string, int, double&);
	bool	checkValidDate();

	std::string				strDataFile;
	std::map<long, sData>	exchange;
	long					date[3];
};

#endif // !BITCOINEXCHANGE
