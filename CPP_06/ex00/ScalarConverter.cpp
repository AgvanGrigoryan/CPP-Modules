#include "ScalarConverter.hpp"
#include <sys/types.h>


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

// double convertToDouble(std::string literal) {
// 	std::stringstream ss(literal);

// 	float a = 0.0;
// 	std::cout << "float: ";

// 	ss >> a;
// 	if (ss.fail())
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << a << std::endl;
// }

// float convertToFloat(double asDouble) {
// 	std::stringstream ss(literal);

// 	float a = 0.0;
// 	std::cout << "float: ";

// 	ss >> a;
// 	if (ss.fail())
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << a << std::endl;
// }

// int convertToInt(float asFloat) {
// 	int asInt = 

// 	ss >> a;
// 	if (ss.fail())
// 		std::cout << "impossible" << std::endl;
// 	else
// 		std::cout << a << std::endl;
// }

// char convertToChar(float asFloat) {
// 	std::stringstream ss;
// 	bool	isPossible = false;
// 	bool	isDisplayable = false;
// 	char	asChar = 0;

// 	asChar = asFloat;
// 	if (std::floor(asFloat) == asFloat && asFloat >= 0 && asFloat <= 256) {
// 		isPossible = true;
// 		if (std::isprint(asChar))
// 			isDisplayable = true;
// 	}

// 	std::cout << "char: ";
// 	if (!isPossible)
// 		std::cout << "impossible" << std::endl;
// 	else if (!isDisplayable)
// 		std::cout << "Non displayable" << std::endl;
// 	else
// 		std::cout << asChar << std::endl;
// 	return (asChar);
// }
struct LiteralInfo {
	bool	isNaN;
	bool	isPositive;
	bool	isDecimal;
	double	asDouble;
	float	asFloat;
	char	asChar;
	int		asInt;
};

void	validateLiteral(const std::string& literal, LiteralInfo& info) {
	if (literal.empty() || (literal.size() > 1 && std::isalpha(literal[0]))) {
		info.isNaN = true;
	}
	if (literal[0] != '-')
		info.isPositive = true;
	if (literal[literal.size() - 1] == 'f')
		info.isDecimal = true;
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
	LiteralInfo info;

	validateLiteral(literal, info);
	// info.asDouble = convertToDouble(literal);
	// info.asFloat = convertToFloat(asDouble);
	// info.asInt = convertToInt(asFloat);
	// info.asChar = convertToChar(asInt);

	std::stringstream ss(literal);

	char c = 0;
	ss >> c;
	std::cout << c << std::endl;
}