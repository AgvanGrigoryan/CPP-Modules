#include <iostream>
#include "Base.hpp"

int main(void) {
	srand(time(0));
{
	std::cout << "\033[0;035m" << "Testing identify(Base *p):" << "\033[0m" << std::endl;
	Base* class_a = new A;
	Base* class_b = new B;
	Base* class_c = new C;

	std::cout << "\033[0;34m" << "(class A):" << "\033[0m" << std::endl;
	identify(class_a);
	std::cout << "\033[0;34m" << "(class B):" << "\033[0m" << std::endl;
	identify(class_b);
	std::cout << "\033[0;34m" << "(class C):" << "\033[0m" << std::endl;
	identify(class_c);

	delete class_a;
	delete class_b;
	delete class_c;
}
{
	std::cout << "\n\033[0;035m" << "Testing identify(Base &p):" << "\033[0m" << std::endl;
	Base* class_a = new A;
	Base* class_b = new B;
	Base* class_c = new C;

	std::cout << "\033[0;34m" << "(class A):" << "\033[0m" << std::endl;
	identify(*class_a);
	std::cout << "\033[0;34m" << "(class B):" << "\033[0m" << std::endl;
	identify(*class_b);
	std::cout << "\033[0;34m" << "(class C):" << "\033[0m" << std::endl;
	identify(*class_c);

	delete class_a;
	delete class_b;
	delete class_c;
}
{
	Base *ptr;
	ptr = generate();

	std::cout << "\n\033[0;035m" << "Testing generate():" << "\033[0m" << std::endl;

	identify(ptr);
	delete ptr;
}
	return (0);
}
