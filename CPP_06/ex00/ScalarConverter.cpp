#include "ScalarConverter.hpp"
#include <sys/types.h>

struct LiteralInfo {
	bool	isPseudo;
	bool	isNaN;
	// bool	isDecimal;
	double	asDouble;
	float	asFloat;
	char	asChar;
	int		asInt;
	uint	precision;
	const std::string	literal;
};

ScalarConverter::ScalarConverter() {
	std::cout << "Default ScalarConverter constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& ) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}
ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& ) {
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	return (*this);
}

double convertToDouble(const LiteralInfo& info) {
	std::stringstream ss(info.literal);

	double a = 0.0;
	std::cout << "Double: ";

	ss >> a;
	if (info.isPseudo)
		std::cout << info.literal << std::endl;
	else if (info.isNaN)
		std::cout << "nan" << std::endl;
	else if (ss.fail())
		std::cout << "ss failed: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(info.precision) << a << std::endl;
	return (a);
}

float convertToFloat(LiteralInfo& info) {
	// std::stringstream ss(literal);
	// ss >> a;

	float f = static_cast<float>(info.asDouble);

	std::cout << "float: ";
	if (info.isPseudo)
		std::cout << info.literal;
	else if (info.isNaN)
		std::cout << "nan";
	else
		std::cout << std::fixed << std::setprecision(info.precision) << f;

	std::cout << 'f' << std::endl;
	return (f);
}

// int convertToInt(float asFloat) {
// 	int asInt = 

// 	ss >> a;
// 	if (ss.fail())
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << a << std::endl;
// }

char convertToChar(LiteralInfo& info) {
	// std::stringstream ss;
	bool	isPossible = false;
	char	asChar = 0;

	if (std::floor(info.asFloat) == info.asFloat && info.asFloat >= 0 && info.asFloat <= 256) {
		isPossible = true;
		asChar = info.asFloat;
	}

	std::cout << "char: ";
	if (info.isPseudo || info.isNaN || !isPossible)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(asChar))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << asChar << std::endl;
	return (asChar);
}

uint	getPrecision(const std::string& str) {
	uint dotPosition = str.find('.');

	if (dotPosition == std::string::npos)
		return (1);
	return (str.size() - dotPosition - 1);
}

void	validateLiteral(const std::string& literal, LiteralInfo& info) {
	if (info.literal == "+inf" || info.literal == "+inff"
		|| info.literal == "-inf" || info.literal == "-inff")
		info.isPseudo = true;
	else if (literal.empty() || (literal.size() > 1 && std::isalpha(literal[0]))) {
		info.isNaN = true;
	}
	

	info.precision = getPrecision(literal);
	std::cout << "\033[0;32m" << "Precision: " << info.precision << "\033[0m" << std::endl;
}


void ScalarConverter::convert(const std::string& literal) {
/* 
Convert literal to these types
char
int
float
double

strtof() instead of std::stof()
istringstream
 */
	LiteralInfo info = {false, false, 0.0, 0.0, 0, 0, 1, literal};

	validateLiteral(literal, info);
	info.asDouble = convertToDouble(info);
	info.asFloat = convertToFloat(info);
	// info.asInt = convertToInt(asFloat);
	info.asChar = convertToChar(info);

	std::stringstream ss(literal);

}