#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : ICharacter {
private:
	std::string name;

public:

	Character();
	Character(const Character& other);
	virtual ~Character();

	operator(const Character& other);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);
}


#endif