#include "ScalarConverter.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Converter expected only 1 paramether as input!" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);
}