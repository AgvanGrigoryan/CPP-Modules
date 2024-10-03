#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		std::cout << "\033[1;35m" << "Cat\n";
		std::cout << "\033[1;32m" << "Calling makeSound using Cat* for an object of the Cat classt" << "\033[0m" << std::endl;
		Cat *cat_ptr = new Cat();
		cat_ptr->makeSound();
		delete cat_ptr;
		std::cout << '\n';
		std::cout << "\033[1;32m" << "Calling makeSound using Animal* for an object of the Cat class" << "\033[0m" << std::endl;
		Animal *animal_ptr = new Cat();
		animal_ptr->makeSound();
		delete animal_ptr;
	}
	{
		std::cout << "\033[1;35m" << "Dog\n";
		std::cout << "\033[1;32m" << "Calling makeSound using Dog* for an object of the Dog class" << "\033[0m" << std::endl;
		Dog *dog_ptr = new Dog();
		dog_ptr->makeSound();
		delete dog_ptr;
		std::cout << '\n';
		std::cout << "\033[1;32m" << "Calling makeSound using Animal* for an object of the Dog class" << "\033[0m" << std::endl;
		Animal *animal_ptr = new Dog();
		animal_ptr->makeSound();
		delete animal_ptr;
	}
	// An error occurs when we try to create an object of abstract class type 'Animal'
	// Animal *animal_ptr = new Animal();

	return 0;
}