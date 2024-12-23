#include "ScalarConverter.hpp"
#include <sys/types.h>

struct LiteralInfo {
	bool	isPseudo;
	bool	isNaN;
	double	asDouble;
	size_t	precision;
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

void convertToDouble(const LiteralInfo& info) {
	std::cout << "Double: ";
	if (info.isPseudo)
		std::cout << info.literal << std::endl;
	else if (info.isNaN)
		std::cout << "nan" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(info.precision) << info.asDouble << std::endl;
}

void convertToFloat(LiteralInfo& info) {
	float f = static_cast<float>(info.asDouble);

	std::cout << "float: ";
	if (info.isPseudo)
		std::cout << info.literal << std::endl;
	else if (info.isNaN)
		std::cout << "nanf" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(info.precision) << f << 'f' << std::endl;
}

void convertToInt(LiteralInfo& info) {

	std::cout << "int: ";
	if (info.isPseudo ||info.isNaN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(info.asDouble) << std::endl;
}

void convertToChar(LiteralInfo& info) {
	// std::stringstream ss;
	bool	isPossible = false;
	char	asChar = 0;

	if (std::floor(info.asDouble) == info.asDouble && info.asDouble >= 0.0 && info.asDouble <= 256.0) {
		isPossible = true;
		asChar = static_cast<char>(info.asDouble);
	}

	std::cout << "char: ";
	if (info.isPseudo || info.isNaN || !isPossible)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(asChar))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << asChar << std::endl;
}

size_t	getPrecision(const std::string& str) {
	size_t dotPosition = str.find('.');

	if (dotPosition == str.npos)
		return (1);
	return (str.size() - dotPosition - 1);
}

void	validateLiteral(LiteralInfo& info) {
	if (info.literal.empty()) {
		info.isNaN = true;
		return;
	}
	if (info.literal == "+inf" || info.literal == "+inff"
		|| info.literal == "-inf" || info.literal == "-inff") {
		info.isPseudo = true;
		return;
	}
	else if (info.literal.size() > 1) { // checks if in literal is external symbols like
		size_t		i = 0;
		size_t	dot_pos = info.literal.find('.');

		if (info.literal[0] == '-' || info.literal[0] == '+')
			i++;
		for (; i < info.literal.size(); i++) {
			if (i != dot_pos && !isdigit(static_cast<unsigned long>(info.literal[i]))) {
				info.isNaN = true;
				return;
			}
		}
		std::stringstream ss(info.literal);
		ss >> info.asDouble;
	}
	else if (!std::isdigit(info.literal[0])) {
		info.asDouble = static_cast<unsigned long>(info.literal[0]);
	}
	else
		info.asDouble = static_cast<unsigned long>(info.literal[0]) - '0';
	

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
	LiteralInfo info = {false, false, 0.0, 1, literal};

	validateLiteral(info);
	info.precision = getPrecision(info.literal);

	convertToDouble(info);
	convertToFloat(info);
	convertToInt(info);
	convertToChar(info);

	std::stringstream ss(literal);

}