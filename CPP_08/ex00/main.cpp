
#include <iostream>
#include <vector>
#include "easyfind.hpp"

void testFound() {
	int init_values[] = {1,2,3,4,5};
	std::vector<int> container(init_values, init_values + sizeof(init_values) / sizeof(*init_values));
	try {
		std::vector<int>::iterator it = easyfind(container, 3);
		std::cout << "Found: " << *it << " at position " << std::distance(container.begin(), it) << '\n';
	} catch (const std::exception& e) {
		std::cerr << "Test failed: " << e.what() << '\n';
	}
}

void testNotFound() {
	int init_values[] = {1,2,3,4,5};
	std::vector<int> container(init_values, init_values + sizeof(init_values) / sizeof(*init_values));
	try {
		std::vector<int>::iterator it = easyfind(container, 6);
		std::cout << "Found: " << *it << '\n'; // This should never run
	} catch (const std::exception& e) {
		std::cout << "Not found: " << e.what() << '\n';
	}
}

void testEmptyContainer() {
	std::vector<int> container;
	try {
		std::vector<int>::iterator it = easyfind(container, 1);
		std::cout << "Found: " << *it << '\n'; // This should never run
	} catch (const std::exception& e) {
		std::cout << "Empty container: " << e.what() << '\n';
	}
}

void testBoundaryCases() {
	int init_values[] = {10,20,30,40,50};
	std::vector<int> container(init_values, init_values + sizeof(init_values) / sizeof(*init_values));
	try {
		std::vector<int>::iterator it = easyfind(container, 10); // First element
		std::cout << "Found first element: " << *it << '\n';

		it = easyfind(container, 50); // Last element
		std::cout << "Found last element: " << *it << '\n';
	} catch (const std::exception& e) {
		std::cerr << "Boundary test failed: " << e.what() << '\n';
	}
}

int main() {
	std::cout << "Test 1: Element found\n";
	testFound();

	std::cout << "\nTest 2: Element not found\n";
	testNotFound();

	std::cout << "\nTest 3: Empty container\n";
	testEmptyContainer();

	std::cout << "\nTest 4: Boundary cases\n";
	testBoundaryCases();

	return 0;
}