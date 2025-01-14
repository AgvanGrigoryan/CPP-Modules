#include "Base.hpp"

Base* generate(void) {
	unsigned int	classNum;
	Base*			object;
	
	classNum = rand() % 3;
	switch (classNum) {
		case 0:
			object = new A();
			break;
		case 1:
			object = new B();
			break;
		case 2:
			object = new C();
			break;
	}
	return (object);
}

void identify(Base* p) {
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << 'A' << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << 'B' << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << 'C' << std::endl;
	else
		std::cout << "The type has not been identified" << std::endl;
}

void identify(Base& p) {
	try {
		Base& temp = dynamic_cast<A &>(p);
		(void)temp;
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception& e) {};
	try {
		Base& temp = dynamic_cast<B &>(p);
		(void)temp;
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception& e) {};
	try {
		Base& temp = dynamic_cast<C &>(p);
		(void)temp;
		std::cout << "C" << std::endl;
		return;
	}
	catch (const std::exception& e) {};
	std::cout << "The type has not been identified" << std::endl;

}
