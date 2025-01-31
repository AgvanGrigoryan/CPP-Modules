#include "PmergeMe.hpp"
#include <deque>
#include <iostream>

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cerr << argv[0] << " expected positive integer sequence as argument" << std::endl;
		return (-1);
	}
	try {
		PmergeMe sorter;
		std::deque<int> deq = sorter.parse_int_sequence<std::deque<int> >(argv, argc);
		std::vector<int> vec = sorter.parse_int_sequence<std::vector<int> >(argv, argc);
		sorter.print_result(vec, deq);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}