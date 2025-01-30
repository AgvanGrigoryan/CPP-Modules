#include "PmergeMe.hpp"
#include <deque>
#include <iostream>
#include <ctime>

template <typename CT>
double calculate_sorting_time(PmergeMe& sorter, CT& container) {
	std::clock_t start = std::clock();
	container = sorter.sort<CT>(container);
	std::clock_t end = std::clock();
	return ((static_cast<double>(end - start) * 1000000) / CLOCKS_PER_SEC);
}

void	print_result(PmergeMe& sorter, std::vector<int>& vec, std::deque<int>& deq) {
	std::cout << "Before:\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	double vector_time = calculate_sorting_time(sorter, vec);
	double deque_time = calculate_sorting_time(sorter, deq);
	std::cout << "\nAfter:\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vector_time << " us" << std::endl;;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deque_time << " us" << std::endl;;
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		std::cerr << argv[0] << " expected positive integer sequence as argument" << std::endl;
		return (-1);
	}
	try {
		PmergeMe sorter;
		std::deque<int> deq = sorter.parse_int_sequence<std::deque<int> >(argv, argc);
		std::vector<int> vec = sorter.parse_int_sequence<std::vector<int> >(argv, argc);
		print_result(sorter, vec, deq);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}