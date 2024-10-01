#include "Character.hpp"

Character::Character() : name("noname") {
	std::cout << "Character Default constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(const std::string& new_name) : name(new_name) {
	std::cout << "Character parameter constructor called" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name) {
	int	i;

	std::cout << "Character Copy constructor called" << std::endl;
	for (i = 0; i < INVENTORY_SIZE && other.inventory[i] != NULL; i++)
		inventory[i] = other.inventory[i]->clone();
	while (i < INVENTORY_SIZE)
		inventory[i++] = NULL;
}

Character::~Character() {
	for (int i = 0; i < INVENTORY_SIZE; i++)
		if (inventory[i] != NULL)
			delete inventory[i];
	std::cout << "Character Destructor called" << std::endl;
}

Character& Character::operator=(const Character& other) {
	int	i;

	std::cout << "Character copy assignment operator called" << std::endl;
	if (this != &other)
	{
		name = other.name;
		for (i = 0; i < INVENTORY_SIZE && other.inventory[i] != NULL; i++)
		{
			delete inventory[i];
			inventory[i] = other.inventory[i]->clone();
		}
		while (i < INVENTORY_SIZE)
			inventory[i++] = NULL;
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
		if (inventory[i] == NULL) {
			inventory[i] = m;
			break;
		}
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > INVENTORY_SIZE)
		return ;
	if (inventory[idx] != NULL)
		inventory[idx] = NULL;
	std::cout << "Unequip called" << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > INVENTORY_SIZE)
		return ;
	if (inventory[idx] != NULL)
		inventory[idx]->use(target);
}
