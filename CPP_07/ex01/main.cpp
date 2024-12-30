#include <iostream>
#include "iter.hpp"

template <typename T> void print(T a) {
	std::cout << a << std::endl;
}

int main(void) {
	int arr[] = {1, 2, 7, 4, 9};

	iter(arr, 5, print);
}