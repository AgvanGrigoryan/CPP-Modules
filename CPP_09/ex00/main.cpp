// #include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]) {
	std::string inputFile("");
	if (argc == 2)
		inputFile = argv[1];

	try {
		BitcoinExchange btc;

		btc.exchange(inputFile);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}