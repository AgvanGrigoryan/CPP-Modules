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

	}
		// std::cout << std::endl;
		// std::cout << "\033[32mLearning Ice and Cure Materias\033[0m" << std::endl;
		// for (unsigned int j = 0; j < size; j++) {
		// 	std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		// 	sources[j]->learnMateria(new Ice());
		// 	sources[j]->learnMateria(new Cure());
		// }
		// std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;

		// std::cout << std::endl;
		// std::cout << "\033[32mCreating Characters\033[0m" << std::endl;
		// Character* me = new Character("me");
		// Character* bob = new Character("bob");

		// std::cout << std::endl;
		// std::cout << "\033[32mEquipping Materias to Characters\033[0m" << std::endl;
		// AMateria* tmp;
		// tmp = sources[0]->createMateria("ice");
		// me->equip(tmp);
		// tmp = sources[0]->createMateria("cure");
		// me->equip(tmp);

		// tmp = sources[1]->createMateria("ice");
		// bob->equip(tmp);
		// tmp = sources[1]->createMateria("cure");
		// bob->equip(tmp);

		// std::cout << std::endl;
		// std::cout << "\033[32mUsing Materias\033[0m" << std::endl;
		// me->use(0, *bob);
		// me->use(1, *bob);
		// bob->use(0, *me);
		// bob->use(1, *me);

		// std::cout << std::endl;
		// std::cout << "\033[31mDeleting MateriaSource and Characters\033[0m" << std::endl;
		// for (unsigned int j = 0; j < size; j++) {
		// 	std::cout << "\033[34m---------------------------------------------\033[0m" << std::endl;
		// 	delete sources[j];
		// }
		// delete me;
		// delete bob;

		// std::cout << std::endl;
		// std::cout << "\033[35m***********************************************\033[0m" << std::endl;
		// std::cout << std::endl;

	return 0;
}




// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }