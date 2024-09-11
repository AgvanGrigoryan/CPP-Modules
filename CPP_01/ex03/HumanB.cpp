#include "HumanB.hpp"

void	HumanB::attack(void)
{
	std::string	weaponType = (weapon == NULL) ? "Hand" : weapon->getType();
	std::cout << name << " attacks with their " << weaponType << std::endl;
}

void	HumanB::setWeapon(Weapon&	new_weapon)
{
	weapon = &new_weapon;
}

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL) {}