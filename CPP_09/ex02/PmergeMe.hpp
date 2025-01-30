#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>

class PmergeMe {
	
};

template <typename CT>
CT parse_int_sequence(const std::string &sequence) {
	CT container;
	std::stringstream ss(sequence);
	int number;
	while (ss >> number) {
		if (number < 0)
			throw std::invalid_argument("Non positive value in sequance");
		container.push_back(number);
	}
	for (size_t i = 0; i < container.size(); i++) {
		std::cout << container[i] << std::endl;
	}
	if (ss.fail() && !ss.eof())
		throw std::invalid_argument("Invalid sequence");
	return (container);
}
#endif