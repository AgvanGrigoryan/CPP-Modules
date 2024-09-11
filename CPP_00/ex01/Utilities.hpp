#ifndef UTILITIES_HPP
# define UTILITIES_HPP

#include <iostream>

namespace ft{

bool isAlpha(const char& ch);
bool isDigit(const char& ch);
bool isAllLetters(const std::string& str);
bool isAllDigits(const std::string& str);
std::string truncate_string(const std::string& str, std::size_t max_length);
std::string trim(std::string& str);
}

#endif
