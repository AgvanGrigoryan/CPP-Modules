#include "PmergeMe.hpp"
#include <stdexcept>

PmergeMe::PmergeMe() {
	std::cout << "Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& ) {
	std::cout << "Default constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ) {
	std::cout << "Default constructor called" << std::endl;
	return (*this);
}

PmergeMe::~PmergeMe() {
	std::cout << "Default constructor called" << std::endl;
}



void	PmergeMe::print_result(std::vector<int>& vec, std::deque<int>& deq) {
	std::cout << "Before:\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	double vector_time = calculate_sorting_time(*this, vec);
	double deque_time = calculate_sorting_time(*this, deq);
	std::cout << "\nAfter:\t";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << ' ';
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vector_time << " us" << std::endl;;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque : " << deque_time << " us" << std::endl;;
}