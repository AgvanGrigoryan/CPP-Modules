#include "Character.hpp"

Character::Character() : name("noname") {
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = nullptr;
}

Character::Character(const std::string& new_name) : name(new_name) {
	std::cout << "Character parameter constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = nullptr;
}

Character::Character(const Character& other) : name(other.name) {
	int	i;

	std::cout << "Character Copy constructor called" << std::endl;
	for (i = 0; i < INVENTORY_SIZE && other.inventory[i] != nullptr; i++)
		inventory[i] = other.inventory[i]->clone();
	for (;i < INVENTORY_SIZE; i++)
		inventory[i] = nullptr;
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (inventory[i] != nullptr)
			delete inventory[i];
	std::cout << "Character Destructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
	int	i;

	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (i = 0; i < INVENTORY_SIZE && other.inventory[i] != nullptr; i++)
		{
			delete inventory[i];
			inventory[i] = other.inventory[i]->clone();
		}
		while (i < INVENTORY_SIZE)
			inventory[i++] = nullptr;
	}
	return (*this);
}

std::string const & Character::getName() const {
	return (name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (inventory[i] == m)
			return ;

	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (inventory[i] == nullptr) {
			inventory[i] = m;
			break;
		}
}

void Character::unequip(int idx) {
	(void) idx;
	std::cout << "Unequip called" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	(void) idx;
	(void) target;
	std::cout << "Use called" << std::endl;
}
