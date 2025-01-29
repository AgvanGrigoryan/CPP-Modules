#include "BitcoinExchange.hpp"
#include <cstddef>
#include <stdexcept>
#include <sys/_types/_ssize_t.h>

BitcoinExchange::BitcoinExchange() {
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	load_data();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : priceData(other.priceData) {
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

void	BitcoinExchange::load_data() {
	std::ifstream file(DATA_CSV);
	if (!file.is_open()) {
		throw std::runtime_error(std::string("Could not open the file ") + DATA_CSV);
	}

	std::string line;
	size_t		line_number = 1;
	std::string	dateStr;
	std::string	priceStr;
	std::time_t	date;
	float		price;

	std::getline(file, line); // to skip first line
	while (std::getline(file, line)) {
		line_number++;
		try {
			parseLine(line, dateStr, priceStr, ',');
			date = stringToDate(dateStr);
			price = stringToFloat(priceStr);
			priceData[date] =  price;
		}
		catch (const std::exception& e) {
			std::cerr << "\033[0;31m" << '[' << DATA_CSV << ": " << line_number << "] " << e.what() << "\033[0m" << std::endl;
		}
	}
}

void	BitcoinExchange::exchange(const std::string& inputFile) {
	std::ifstream file(inputFile);
	if (!file.is_open()) {
		throw std::runtime_error(std::string("Could not open the file: ") + inputFile);
	}

	std::string line;
	size_t		line_number = 1;
	std::string	dateStr;
	std::string	quantityStr;
	std::time_t	date;
	float		quantity;
	std::getline(file, line); // to skip first line
	while (std::getline(file, line)) {
		line_number++;
		try {
			parseLine(line, dateStr, quantityStr, '|');
			date = stringToDate(dateStr);
			quantity = stringToFloat(quantityStr);
			if (quantity > 1000.0)
				throw std::runtime_error("The number is too large.");
			std::cout << dateStr << " => " << quantity << " = " << priceData[date] * quantity << std::endl;
			
		}
		catch (const std::exception& e) {
			std::cerr << "\033[0;31m" << '[' << inputFile << ": " << line_number << "] " << e.what() << "\033[0m" << std::endl;
		}
	}
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

	std::stringstream ss;
	std::time_t date;
	const char	delimiter = '-';
	size_t first_dash_position;
	size_t last_dash_position;

	first_dash_position = str.find_first_of(delimiter);
	last_dash_position = str.find_last_of(delimiter);
	if (first_dash_position == str.npos || last_dash_position == str.npos 
		|| first_dash_position == last_dash_position
		|| str.find_first_of(delimiter,first_dash_position + 1) != last_dash_position)
		throw std::runtime_error("Date isn't folowing to format: Year-Month-Day");
	
	ss << str.substr(0, first_dash_position);;
	ss >> dateTm.tm_year;
	if (ss.fail())
		throw std::runtime_error("Date isn't folowing to format: Year-Month-Day");

	ss.clear();
	ss << str.substr(first_dash_position + 1, last_dash_position - first_dash_position - 1);;
	ss >> dateTm.tm_mon;
	if (ss.fail())
		throw std::runtime_error("Date isn't folowing to format: Year-Month-Day");

	ss.clear();
	ss << str.substr(last_dash_position + 1);
	ss >> dateTm.tm_mday;
	if (ss.fail())
		throw std::runtime_error("Date isn't folowing to format: Year-Month-Day");

	if (!isValidDate(dateTm.tm_year, dateTm.tm_mon, dateTm.tm_mday))
		throw std::runtime_error("invalid Date");
	
	dateTm.tm_year -= 1900;
	dateTm.tm_mon -= 1;

	date = std::mktime(&dateTm);
	if (date == -1)
		throw std::runtime_error("mktime: Invalid Date");
	return (date);
}

float BitcoinExchange::stringToFloat(const std::string& str) {
	std::stringstream ss(str);
	float result;

	ss >> result;
	if (result < 0)
		throw std::runtime_error("not a positive number");
	if (ss.fail() || !ss.eof() || std::isinf(result))
		throw std::runtime_error("Invalid Value format");
	return (result);
}

void	BitcoinExchange::parseLine(const std::string& line, std::string &dateStr, std::string &valueStr, char delimiter) {

	size_t delimiter_pos;

	delimiter_pos = line.find(delimiter);
	if (delimiter_pos == line.npos || delimiter_pos != line.find_last_of(delimiter))
		throw std::runtime_error(std::string("Line isn't folowing to format: \"date ") + delimiter + " value\"");

	dateStr = line.substr(0, delimiter_pos);
	valueStr = line.substr(delimiter_pos + 1);
}

bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
    if (year < 1900 || year > 9999) // Reasonable range
        return false;
    if (month < 1 || month > 12)
        return false;

    // Days in each month
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int maxDays = daysInMonth[month - 1];
    if (month == 2 && isLeapYear(year))
        maxDays = 29; // Adjust for leap years

    return day >= 1 && day <= maxDays;
}
