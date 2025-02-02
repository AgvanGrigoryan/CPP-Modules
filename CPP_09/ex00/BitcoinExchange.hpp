#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

#include <map>

#ifndef DATA_SCV
# define DATA_CSV "data.csv"
#endif

class BitcoinExchange {
private:
	std::map<std::time_t, float> priceData;

	void			parseLine(const std::string& line, std::string &date, std::string &price, char expected_delimiter);
	std::time_t		stringToDate(const std::string& str);
	float			stringToFloat(const std::string& str);
	float			getPriceByDate(const std::time_t date) const;
	void 			load_data();

	bool isLeapYear(int year);
	bool isValidDate(int year, int month, int day);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange();
	BitcoinExchange& operator=(const BitcoinExchange& other);
	void			exchange(const std::string& inputFile);
};

#endif