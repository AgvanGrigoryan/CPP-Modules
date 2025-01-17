#include <iostream>
#include <Array.hpp>

int main(void) {
	
	std::cout << std::endl;
	std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	std::cout << std::endl;

	{
		std::cout << "\033[32mCreating Array using default constructor\033[0m" << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		Array<int> emptyArray;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "Size: " << emptyArray.size() << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[35m***********************************************\033[0m" << std::endl;
	std::cout << std::endl;

	{
		std::cout << "\033[32mCreating Array using paramether constructor\033[0m" << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		Array<int> intArray(10);
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "Size: " << intArray.size() << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[33mFilling of array\033[0m" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
			intArray[i] = i + 1;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[34mPrinting an array\033[0m" << std::endl;
		for (unsigned int i = 0; i < intArray.size(); i++)
			std::cout << intArray[i] << ' ';
		std::cout << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "element in the range intArray[4]: " << intArray[4] << std::endl;
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "element out of range intArray[99]: ";
		try {
			std::cout << intArray[99] << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[0;31mException was thrown" << std::endl;
		}
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		std::cout << "element out of range intArray[-1]: ";
		try {
			std::cout << intArray[-1] << std::endl;
		}
		catch (const std::exception& e) {
			std::cout << "\033[0;31mException was thrown" << std::endl;
		}
		
		std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;

			{
			// COPY CONSTRUCTOR
			Array<int> copyArray(intArray);

			std::cout << std::endl;
			std::cout << "\033[32mCopy Constructor: copyArray(intArray)\033[0m" << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting copyArray\033[0m" << std::endl;
			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[33mChanging an copyArray\033[0m" << std::endl;
			for (unsigned int num = 10, i = 0; i < copyArray.size(); i++, num--)
				copyArray[i] = num;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting copyArray \033[33mAfter the changes\033[0m" << std::endl;
			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting intArray \033[33mAfter the changes\033[0m" << std::endl;
			for (unsigned int i = 0; i < intArray.size(); i++)
				std::cout << intArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			}
			{
			// COPY ASSIGNMENT OPERATOR
			Array<int> copyArray;

			copyArray = intArray;
			std::cout << std::endl;
			std::cout << "\033[32mCopy assignment operator: copyArray(intArray)\033[0m" << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting copyArray\033[0m" << std::endl;
			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[33mChanging an copyArray\033[0m" << std::endl;
			for (unsigned int num = 10, i = 0; i < copyArray.size(); i++, num--)
				copyArray[i] = num;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting copyArray \033[33mAfter the changes\033[0m" << std::endl;
			for (unsigned int i = 0; i < copyArray.size(); i++)
				std::cout << copyArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			std::cout << "\033[34mPrinting intArray \033[33mAfter the changes\033[0m" << std::endl;
			for (unsigned int i = 0; i < intArray.size(); i++)
				std::cout << intArray[i] << ' ';
			std::cout << std::endl;
			std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
			}

	}
	return 0;
}