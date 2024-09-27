#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : AMateria {
public:
	Ice();
	virtual AMateria* clone() const;
};

Ice::Ice(/* args */)
{
}

Ice::~Ice()
{
}


#endif