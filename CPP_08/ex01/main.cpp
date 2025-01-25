#include "Span.hpp"


int main(void) {
	try {
		std::cout << "\033[0;32m[" << "Testing addNumber" << "]\033[0m" << std::endl;
		Span sp = Span(10);
		sp.addNumber(77);
		sp.addNumber(10);
		sp.addNumber(88);
		std::cout << "LongestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "ShortestSpan: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
	// -------------------------------------------------------------------------------------
	try {
		std::cout << "\033[0;32m[" << "Testing insert" << "]\033[0m" << std::endl;
		Span sp = Span(10);
		int arr[] = {1,2,3,4,10,12,20};
		sp.insert(arr, arr + sizeof(arr) / sizeof(*arr));
	}
	catch (const std::exception& e) {
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
	// -------------------------------------------------------------------------------------
	try {
		Span sp(10);
		std::cout << "\033[0;32m[" << "Testing longestSpan on empty span" << "]\033[0m" << std::endl;
		long long	longestspan = sp.longestSpan();
		std::cout << "LongestSpan: " << longestspan << std::endl;

	}
	catch (const std::exception& e){
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
	// -------------------------------------------------------------------------------------
	try {
		Span sp(10);
		std::cout << "\033[0;32m[" << "Testing shortestSpan" << "]\033[0m" << std::endl;
		long long	shortestspan = sp.shortestSpan();
		std::cout << "ShortestSpan: " << shortestspan << std::endl;
	}
	catch (const std::exception& e){
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
	// -------------------------------------------------------------------------------------
	try {
		Span sp(2);
		std::cout << "\033[0;32m[" << "Add more elements than N" << "]\033[0m" << std::endl;
		std::vector<int> vec(5,10);
		sp.insert(vec.begin(), vec.end());
	}
	catch (const std::exception& e){
		std::cout << "\033[0;31m[" << e.what() << "]\033[0m" << std::endl;
	}
	return 0;
}