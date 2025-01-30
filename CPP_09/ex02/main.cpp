#include "PmergeMe.hpp"
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] << " expected positive integer sequence as argument" << std::endl;
		return (-1);
	}
	try {
		std::vector<int> sequence = parse_int_sequence<std::vector<int> >(std::string(argv[1]));
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}