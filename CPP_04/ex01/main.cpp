#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[100];
	for (int i = 0; i < 50; i++)
		animals[i] = new Dog();
	std::cout << "\n\n";
	for (int i = 50; i < 100; i++)
		animals[i] = new Cat();
	
	for (int i = 0; i < 100; i++)
		delete animals[i];
	
	return 0;
}