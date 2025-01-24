#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename  T::const_iterator	easyfind(const T &container_of_ints, int integer) {
	typename T::const_iterator it = std::find(container_of_ints.begin(), container_of_ints.end(), integer);
	if (it == container_of_ints.end())
		throw std::exception();
	return (it);
}

template <typename T>
typename  T::iterator	easyfind(T &container_of_ints, int integer) {
	typename T::iterator it = std::find(container_of_ints.begin(), container_of_ints.end(), integer);
	if (it == container_of_ints.end())
		throw std::exception();
	return (it);
}

#endif