#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#define INVENTORY_SIZE 4

class Character : ICharacter {
private:
	std::string name;
	AMateria* inventory[INVENTORY_SIZE];
public:

	Character();
	Character(const Character& other);
	Character(const std::string& new_name);
	virtual ~Character();

	Character& operator=(const Character& other);
	virtual std::string const & getName() const;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

	void showInventory() {for (int i = 0; i < INVENTORY_SIZE; i++) std::cout << i << ": " << inventory[i] << std::endl;};
};


#endif