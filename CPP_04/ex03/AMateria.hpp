#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
protected:
	std::string	type;

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& type);
	virtual ~AMateria();

	AMateria& operator=(const AMateria& other);
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif