#include "BitcoinExchange.hpp"
#include <stdexcept>
#include <sys/_types/_ssize_t.h>

BitcoinExchange::BitcoinExchange() : priceDataFileName(DATA_CSV) {
	std::ifstream file(priceDataFileName);
	std::time_t		date;
	float			price;

	if (!file.is_open()) {
		throw std::runtime_error("Could not open the file.");
	}
	std::string line;
	while (std::getline(file, line)) {
		try {
			parseLine(line, date, price);
			priceData[date] =  price;
		}
		catch (const std::exception& e) {
			// delete all inserted strings in map
			std::cout << "\033[0;31m" << e.what() << "]\033[0m" << std::endl;
		}
	}
	std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : priceDataFileName(DATA_CSV), priceData(other.priceData) {
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
	std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	std::cout << "BitcoinExchange copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	this->priceData = other.priceData;
	return (*this);
}


std::time_t	BitcoinExchange::stringToDate(const std::string& str) {
	std::tm dateTm;

dateTm.tm_sec = 0;   // Seconds (0-60)
dateTm.tm_min = 0;   // Minutes (0-59)
dateTm.tm_hour = 0;  // Hours (0-23)
dateTm.tm_mday = 0;  // Day of the month (1-31)
dateTm.tm_mon = 0;   // Month (0-11, January is 0)
dateTm.tm_year = 0;  // Years since 1900
dateTm.tm_wday = 0;  // Day of the week (0-6, Sunday is 0)
dateTm.tm_yday = 0;  // Day of the year (0-365)
dateTm.tm_isdst = 0; // Daylight Saving Time flag

	std::stringstream ss(str);
	std::time_t date;
	char	delimiter;

	ss >> dateTm.tm_year >> delimiter;
	if (ss.fail() || !ss.eof() || delimiter != '-')
		throw std::runtime_error("Date isn't folowing to format: Year-Month-Day");
	ss >> dateTm.tm_mon >> delimiter >> dateTm.tm_mday;
	if (ss.fail() || !ss.eof() || delimiter != '-')
		throw std::runtime_error("Date isn't folowing to format: Year-Month-Day");
	dateTm.tm_year -= 1900;
	dateTm.tm_mon -= 1;
	
	date = std::mktime(&dateTm);
	if (date == -1)
		throw std::runtime_error("Invalid Date format");
	return (date);
}

float BitcoinExchange::stringToFloat(const std::string& str) {
	std::stringstream ss(str);
	float result;

	ss >> result;
	if (ss.fail() || !ss.eof() || std::isinf(result))
		throw std::runtime_error("Invalid Value format");
	return (result);
}

void	BitcoinExchange::parseLine(const std::string& line, std::time_t &date, float &price) {
	std::stringstream ss(line);
	std::string	dateStr;
	std::string	priceStr;
	char		delimiter;

	ss >> dateStr >> delimiter >> priceStr;
	if (ss.fail() || !ss.eof() || delimiter != '|')
		throw std::runtime_error("Line isn't folowing to format: \"date | value\"");
	// functions throw an error when the strings do not follow the correct format
	date = stringToDate(dateStr);
	price = stringToFloat(priceStr);
}

	void	BitcoinExchange::showPriceDate() {
		std::map<std::time_t, float>::iterator it;
		for (it = priceData.begin(); it != priceData.end(); it++) {
			std::cout << it->first << " | " << it->second << std::endl;
		}
	}
