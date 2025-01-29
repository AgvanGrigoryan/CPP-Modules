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
	std::map<std::time_t, float> priceData;

	void			parseLine(const std::string& line, std::string &date, std::string &price, char expected_delimiter);
	std::time_t		stringToDate(const std::string& str);
	float			stringToFloat(const std::string& str);
	void 			load_data();
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);
	void			exchange(const std::string& inputFile);
	// void				showPriceDate();
};

#endif