#include "BitcoinExchange.hpp"
#include <ctime>
#include <string>
#include <utility>

btc::btc(){}

btc::btc(std::string strData)
{
	dataStrBtc = strData;
}

btc::~btc()
{
	if (!dataStrBtc.empty())
		dataStrBtc.clear();
	exchange.clear();
}

btc::btc(const btc &bitcoin){
	*this = bitcoin;
}

btc &btc::operator=(const btc &otherBitcoin){
	if (this != &otherBitcoin)
	{
		this->dataStrBtc = otherBitcoin.getDataBtc();
		this->exchange = otherBitcoin.getExchange();
	}
	return (*this);
}

std::map<std::time_t, double> btc::getExchange() const{
	return (exchange);
}

std::string	btc::getDataBtc() const{
	return (dataStrBtc);
}

void	btc::printError(int error, std::string line)
{
	switch (error) {
		case 2: std::cout << "Error: bad input => " << line << '\n';
			break;
		case 3: std::cout << "Error: not a positive number." << '\n';
			break;
		case 4: std::cout << "Error: too large a number." << '\n';
	}
}

bool	btc::checkValidDate(std::tm &tDate)
{
	if (tDate.tm_year == -1 || tDate.tm_mon == -1 || tDate.tm_mday == -1)
		return (false);
	if (tDate.tm_year < 2008 || tDate.tm_year > 2023)
		return (false);
	if (tDate.tm_mon > 12 || tDate.tm_mon == 0)
		return (false);
	if (tDate.tm_mday > 31 || tDate.tm_mday == 0)
		return (false);
	if (tDate.tm_mday == 31 && (tDate.tm_mon == 4 || tDate.tm_mon == 6 || tDate.tm_mon == 9 || tDate.tm_mon == 11))
		return (false);
	if (tDate.tm_mon == 2)
	{
		if (tDate.tm_mday > 29)
			return (false);
		if (tDate.tm_mday == 29 && (tDate.tm_year % 100) % 4 != 0)
			return (false);
	}
	return (true);
}

int	btc::checkData(std::string line, int type, std::tm &tDate, double &price)
{
	const char	*delim = "0123456789";
	std::string	line2;
	int			pos = -1;

	if (type == DATABASE && line.length() < 12)
		return (2);
	if (type == EXCHANGE && line.length() < 14)
		return (2);
	line2 = line.substr(0, 4);
	if (line2.find_first_not_of(delim) != std::string::npos)
		return (2);
	tDate.tm_year = std::atoi(line2.c_str());
	line2 = line.substr(5, 2);
	if (line2.find_first_not_of(delim) != std::string::npos)
		return (2);
	tDate.tm_mon = std::atoi(line2.c_str());
	line2 = line.substr(8, 2);
	if (line2.find_first_not_of(delim) != std::string::npos)
		return (2);
	tDate.tm_mday = std::atoi(line2.c_str());
	checkValidDate(tDate);
	if (type == DATABASE)
	{
		line2 = line.substr(11);
		pos = line2.find_first_of('.');
		if (pos >= 0)
			line2.replace(pos, 1, "0");
		if (line2.find_first_not_of(delim) != std::string::npos)
			return (2);
		line2 = line.substr(11);
	}
	else
	{
		line2 = line.substr(13);
		pos = line2.find_first_of(line2, '-');
		if (pos >= 0)
			line2.replace(pos, 1, "0");
		pos = line2.find_first_of('.');
		if (pos >= 0)
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

void	btc::initmap(std::string strData)
{
	double			price;
	std::tm			tDate;
	std::string		line;
	std::ifstream	dataFile;

	if (dataStrBtc.empty())
		dataFile.open(dataStrBtc);
	else
		dataFile.open(strData);
	if (!dataFile.is_open())
		throw fileError("Error: file " + strData + " can't be opened");

	tDate.tm_year = -1; tDate.tm_mon = -1; tDate.tm_mday = -1, price = -1;
	std::getline(dataFile, line);
	if (line != "date,exchange_rate")
		throw dataBaseCorrupted();

	while (!dataFile.eof())
	{
		std::getline(dataFile, line);
		if (checkData(line, DATABASE, tDate, price) != true)
			throw dataBaseCorrupted();
		exchange.insert(std::make_pair(std::mktime(&tDate), price));
		dataFile.peek();
	}
}

void btc::printExchange(std::tm &tDate, double price)
{
	std::time_t time = mktime(&tDate);

	double	dataPrice = exchange.begin()->second;
	for (std::map<std::time_t, double>::iterator it = exchange.begin(); it != exchange.end() && time > it->first; it++)
	{
		dataPrice = it->second;
	}
	std::cout << tDate.tm_year << "-" << tDate.tm_mon << "-" << tDate.tm_mday << " => ";
	std::cout << price << " = " << dataPrice * price << '\n';
}

void btc::parseExchange(std::string strExchange)
{
	double			price;
	std::tm			tDate;
	int				error = 0;
	std::string 	line;
	std::ifstream	exchangeFile;

	exchangeFile.open(strExchange);
	if (!exchangeFile.is_open())
		throw fileError("Error: file " + strExchange + " can't be opened");

	tDate.tm_year = -1, tDate.tm_mon = -1, tDate.tm_mday = -1, price = -1;
	std::getline(exchangeFile, line);
	if (line != "date | value")
	{
		std::cout << "file not exchange dataBase" << '\n';
		return ;
	}

	while (!exchangeFile.eof())
	{
		std::getline(exchangeFile, line);
		error = checkData(line, EXCHANGE, tDate, price);
		if (error == true)
			printExchange(tDate, price);
		else
			printError(error, line);
		exchangeFile.peek();
	}
	exchangeFile.close();
}
