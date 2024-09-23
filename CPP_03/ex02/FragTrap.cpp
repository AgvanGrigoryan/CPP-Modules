#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap() {
	name = "<FragTrap_anonymous>";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

// Paramether Constructor
FragTrap::FragTrap(const std::string& new_name) {
	name = new_name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap parameter constructor called" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (energy_points <= 0) {
		std::cout << "Not enough energy points to attack" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void	FragTrap::highFivesGuys() {
	std::cout << name << "FragTrap High Fives Guyes :)" << std::cout;
}
