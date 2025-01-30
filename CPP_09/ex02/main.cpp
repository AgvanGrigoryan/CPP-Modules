#include "PmergeMe.hpp"
#include <deque>
#include <iostream>


int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cerr << argv[0] << " expected positive integer sequence as argument" << std::endl;
		return (-1);
	}
	try {
		PmergeMe sorter;
		std::deque<int> deq = sorter.parse_int_sequence<std::deque<int> >(std::string(argv[1]));
		std::vector<int> vec = sorter.parse_int_sequence<std::vector<int> >(std::string(argv[1]));
		std::vector<int> sorted_vec = sorter.sort<std::vector<int> >(vec);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}