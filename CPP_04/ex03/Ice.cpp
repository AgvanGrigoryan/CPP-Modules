#include "Ice.hpp"

Ice::Ice() type("ice") {}


virtual AMateria* clone() const {
	return (new Amateria(this->type));
}