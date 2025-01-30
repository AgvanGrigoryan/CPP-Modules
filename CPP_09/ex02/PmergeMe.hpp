#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <deque>

class PmergeMe {
private:
	// std::vector<int>	vec;
	// std::deque<int>		deq;

public:
	template <typename CT>
	CT		parse_int_sequence(const std::string &sequence);
	template <typename CT>
	CT		sort(CT& container);
	template <typename CT>
	void	insertion_sort(CT& left, CT& right);
	template <typename CT>
	void	binary_insertion(CT& container, int value);
};

template <typename CT>
CT	PmergeMe::sort(CT& container) {
	CT big;
	CT small;

	// add base case
	if (container.size() < 2)
		return (container);

	for (size_t i = 0; i < container.size(); i+=2) {

		if (i + 1 == container.size())
			big.push_back(container[i]);
		if (container[i] < container[i + 1]) {
			big.push_back(container[i]);
			small.push_back(container[i + 1]);
		} else {
			small.push_back(container[i]);
			big.push_back(container[i + 1]);
		}
	}
	big = sort(big);
	insertion_sort(big, small);
	return (big);
}

template <typename CT>
void	PmergeMe::insertion_sort(CT& left, CT& right) {
	size_t i = 0;
	size_t elem_index = 0;
	size_t	elems_added = 0;

	while (right.size() != 0) {
		elem_index = static_cast<int>(std::pow(2, i)) - 1;
		if (elem_index >= right.size())
			elem_index = elems_added;
		binary_insertion(left, right[elem_index]);
		left.push_back(right[elem_index]);
		elems_added++;
	}
}

template <typename CT>
void	PmergeMe::binary_insertion(CT& container, int value) {
	size_t left;
	size_t right;
	size_t mid;

	left = 0;
	right = container.size();
	mid = right / 2;
	while (mid != left && mid != right) {
		if (container[mid] < value) {
			left = mid;
		}
		else {
			right = mid;
		}
		mid = (right + left) / 2;
	}
	// insert
	container.insert(container.begin() + mid, value);
}

template <typename CT>
CT PmergeMe::parse_int_sequence(const std::string &sequence) {
	std::stringstream ss(sequence);
	CT container;
	int number;

	while (ss >> number) {
		if (number < 0)
			throw std::invalid_argument("Non positive value in sequance");
		container.push_back(number);
	}
	if (ss.fail() && !ss.eof())
		throw std::invalid_argument("Invalid sequence");
	return (container);
}

#endif