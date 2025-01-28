#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include <map>

#define DATA_CSV "data.csv"

class BitcoinExchange {
private:
	const std::string priceDataFileName;
	std::map<std::time_t, float> priceData;
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);
	static void			parseLine(const std::string& line, std::time_t &date, float &price, char expected_delimiter);
	static std::time_t	stringToDate(const std::string& str);
	static float		stringToFloat(const std::string& str);
	void				showPriceDate();
};

#endif