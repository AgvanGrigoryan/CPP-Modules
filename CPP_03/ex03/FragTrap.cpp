#include "FragTrap.hpp"

// Default Constructor
FragTrap::FragTrap() {
	name = "<FragTrap_anonymous>";
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) {
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

// Paramether Constructor
FragTrap::FragTrap(const std::string& new_name) {
	name = new_name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap parameter constructor called" << std::endl;
}

FragTrap::FragTrap(int) {
	name = "<FragTrap_anonymous>";
	hit_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap special constructor called" << std::endl;
}


FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}


FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string& target) {
	if (hit_points <= 0 || energy_points <= 0) {
		std::cout << name << " doesn't have enough energy or hit points to attack " << target << std::endl;
		return ;
	}
	std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void	FragTrap::highFivesGuys() {
	std::cout << name << "FragTrap High Fives Guyes :)" << std::cout;
}
