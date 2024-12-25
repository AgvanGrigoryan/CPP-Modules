#include <cstdlib>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
	std::cout << "Base Destructor Called" << std::endl;
}

Base* Base::generate(void) {
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
