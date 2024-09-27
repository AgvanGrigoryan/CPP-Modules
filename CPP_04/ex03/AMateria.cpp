#include "AMateria.hpp"

AMateria::AMateria(std::string const & new_type) : type(new_type) {}

std::string const & getType() const {
	return (type);
}

