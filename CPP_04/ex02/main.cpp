#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	std::cout << "\n\n";
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 10; i++)
		delete animals[i];

	// DOG DEEP COPY TESTING
	{
		std::cout << "\033[1;35m\n" << "testing Dog copy" << "\033[0m" << std::endl;
		Dog dog;

		std::cout << "\033[1;32m\n" << "dog first idea" << "\033[0m" << std::endl;
		dog.setIdea(0, "Maybe go to the kitchen and eat the big xachapuri");
		std::cout << dog.getIdea(0) << std::endl;

		std::cout << "\033[1;33m\n" << "copy the dog" << "\033[0m" << std::endl;
		Dog dog2(dog);
		std::cout << "\033[1;33m" << "dog2 first idea before changing: " << "\033[0m" << dog2.getIdea(0) << std::endl;
		dog2.setIdea(0, "Maybe go to sleep, hmmm...");
		std::cout << "\033[1;33m" << "dog2 first idea after changing: " << "\033[0m" << dog2.getIdea(0) << std::endl;
		std::cout << "\033[1;34m" << "dog first idea after changing dog2 idea: " << "\033[0m"  << dog.getIdea(0) << '\n' << std::endl;
	}
	// CAT DEEP COPY TESTING
	{
		std::cout << "\033[1;35m\n\n" << "testing Cat copy" << "\033[0m" << std::endl;
		Cat cat;

		std::cout << "\033[1;32m\n" << "cat first idea" << "\033[0m" << std::endl;
		cat.setIdea(0, "Maybe go to the kitchen and eat bottle of milk");
		std::cout << cat.getIdea(0) << std::endl;

		std::cout << "\033[1;33m\n" << "copy the cat" << "\033[0m" << std::endl;
		Cat cat2(cat);
		std::cout << "\033[1;33m" << "cat2 first idea before changing: " << "\033[0m" << cat2.getIdea(0) << std::endl;
		cat2.setIdea(0, "Maybe go to sleep, hmmm...");
		std::cout << "\033[1;33m" << "cat2 first idea after changing: " << "\033[0m" << cat2.getIdea(0) << std::endl;
		std::cout << "\033[1;34m" << "cat first idea after changing cat2 idea: " << "\033[0m"  << cat.getIdea(0) << '\n' << std::endl;
	}
	// An error occurs when we try to create an object of abstract class type 'Animal'
	// Animal *animal_ptr = new Animal();
	return 0;
}