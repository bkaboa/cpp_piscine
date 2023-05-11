#include "BitcoinExchange.hpp"

btc::btc():strDataFile("data.csv") {}

btc::btc(std::string strData):strDataFile(strData) {}

btc::~btc() {}

btc::btc(const btc &bitcoin){
	*this = bitcoin;
}

btc &btc::operator=(const btc &otherBitcoin){
	if (this != &otherBitcoin)
		this->strDataFile = otherBitcoin.getStrDataFile();
	return (*this);
}

const std::string	&btc::getStrDataFile() const{
	return (strDataFile);
}

void	btc::setStrDataFile(const char *arg) {
	strDataFile = arg;
}

void	btc::printError(int error, std::string line)
{
	switch (error) {
		case 2: std::cout << "Error: bad input => " << line << '\n';
			break;
		case 3: std::cout << "Error: not a positive number." << '\n';
			break;
		case 4: std::cout << "Error: too large a number." << '\n';
			break;
	}
}

bool	btc::checkValidDate()
{
	if (date[0] == -1 || date[0] == -1 || date[0] == -1)
		return (false);
	if (date[0] < 2008 || date[0] > 2023)
		return (false);
	if (date[1] > 12 || date[1] == 0)
		return (false);
	if (date[2] > 31 || date[2] == 0)
		return (false);
	if (date[2] == 31 && (date[1] == 4 || date[1] == 6 || date[1] == 9 || date[1] == 11))
		return (false);
	if (date[1] == 2)
	{
		if (date[2] > 29)
			return (false);
		if (date[2] == 29 && (date[0] % 100) % 4 != 0)
			return (false);
	}
	return (true);
}

int	btc::checkData(std::string line, int type, double &price)
{
	const char	*delim = "0123456789";
	std::string	line2;
	int			pos = -1;

	if (type == DATABASE && line.length() < 12)
		return (2);
	if (type == EXCHANGE && line.length() < 14)
		return (2);
	std::cout << line[4] << '\n' << line[7] << '\n' << line[10] << '\n' << line[10] << line[10] << line[11] << line[12] << '\n';
	if (line[4] != '-' || line[7] != '-')
		return (2);
	if (type == DATABASE && line[10] != ',')
		return (2);
	if (type == EXCHANGE && line.compare(10, 3, " | "))
		return (2);
	line2 = line.substr(0, 4);
	if (line2.find_first_not_of(delim) != std::string::npos)
		return (2);
	date[0] = std::atoi(line2.c_str());
	line2 = line.substr(5, 2);
	if (line2.find_first_not_of(delim) != std::string::npos)
		return (2);
	date[1] = std::atoi(line2.c_str());
	line2 = line.substr(8, 2);
	if (line2.find_first_not_of(delim) != std::string::npos)
		return (2);
	date[2] = std::atoi(line2.c_str());
	if (checkValidDate() == false)
		return (2);
	if (type == DATABASE)
	{
		line2 = line.substr(11);
		pos = line2.find_first_of('.');
		if ((unsigned long)pos != std::string::npos)
			line2.replace(pos, 1, "0");
		if (line2.find_first_not_of(delim) != std::string::npos)
			return (2);
		line2 = line.substr(11);
	}
	else
	{
		line2 = line.substr(13);
		if (line2[0] == '-')
			line2.replace(0, 1, "0");
		pos = line2.find_first_of('.');
		if ((unsigned long)pos != std::string::npos)
			line2.replace(pos, 1, "0");
		if (line2.find_first_not_of(delim) != std::string::npos)
			return (2);
		line2 = line.substr(13);
	}
	price = std::atof(line2.c_str());
	if (price < 0)
		return (3);
	if (type == EXCHANGE && price > 1000)
		return (4);
	return (true);
}

void	btc::setExchangeMap()
{
	double			price;
	std::string		line;
	std::ifstream	file;
	sData			data;

	if (strDataFile.empty())
		throw exceptionError("Error: database string file, not setup");
	file.open(strDataFile.c_str());
	if (!file.is_open())
		throw exceptionError("Error: file " + strDataFile + " can't be opened");
	if (exchange.empty())
		exchange.clear();

	std::getline(file, line);
	if (line != "date,exchange_rate")
		throw exceptionError("error : database corrupted");

	while (!file.eof())
	{
		date[0] = -1; date[1] = -1; date[2] = -1;
		std::getline(file, line);
		if (checkData(line, DATABASE, price) != true)
			throw exceptionError("error : database corrupted");
		data.price = price;
		data.date =	line;
		date[0] = date[0] * 100 + date[1];
		date[0] = date[0] * 100 + date[2];
		exchange.insert(std::pair<long, sData>(date[0], data));
		file.peek();
	}
}

void btc::printExchange(double price, std::string line)
{
	std::map<long, sData>::iterator it = exchange.begin();
	date[0] = date[0] * 100 + date[1];
	date[0] = date[0] * 100 + date[2];

	double	dataPrice = exchange.begin()->second.price;
	for (; it != exchange.end() && date[0] >= it->first; ++it)
		dataPrice = it->second.price;
	std::cout << line.substr(0,10) << " => ";
	std::cout << price << " = " << dataPrice * price << '\n';
}

void btc::parseExchange(std::string strExchange)
{
	double			price;
	int				error = 0;
	std::string 	line;
	std::ifstream	exchangeFile;

	setExchangeMap();
	exchangeFile.open(strExchange.c_str());
	if (!exchangeFile.is_open())
		throw exceptionError("Error: file " + strExchange + " can't be opened");

	std::getline(exchangeFile, line);
	if (line != "date | value")
		throw exceptionError("Error: file " + strExchange + " corrupted");
	while (!exchangeFile.eof())
	{
		date[0] = -1; date[1] = -1; date[2] = -1;
		std::getline(exchangeFile, line);
		error = checkData(line, EXCHANGE, price);
		if (error == true)
			printExchange(price, line);
		else
			printError(error, line);
		exchangeFile.peek();
	}
	exchangeFile.close();
}
