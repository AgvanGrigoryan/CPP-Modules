#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : AMateria {
public:
	Cure();
	Cure(const Cure& other);
	~Cure();

	operator=(const Cure& other);
	virtual AMateria* clone() const;
};

#endif