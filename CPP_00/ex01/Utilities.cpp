#include "Utilities.hpp"

namespace ft{

bool isAlpha(const char& ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

bool isDigit(const char& ch)
{
	return (ch >= '0' && ch <= '9');
}

bool isAllLetters(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (ft::isAlpha(str[i]) == false)
			return false;
	}
	return true;
}

bool isAllDigits(const std::string& str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (ft::isDigit(str[i]) == false)
			return false;
	}
	return true;
}
std::string truncate_string(const std::string& str, std::size_t max_length) {
	if (str.length() > max_length) {
		return str.substr(0, max_length - 1) + '.';
	} else {
		return str;
	}
}

std::string trim(std::string& str)
{
	size_t start = 0;
	size_t end = 0;

	while (start < str.size() && std::isspace(str[start]))
		++start;
	end = str.size();
	while (end > start && std::isspace(str[end - 1]))
		--end;
	return (str.substr(start, end - start));
}

}
