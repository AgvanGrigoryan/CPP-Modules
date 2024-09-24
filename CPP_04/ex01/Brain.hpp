#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define IDEAS_CNT 100

class Brain {
private:
	std::string ideas[IDEAS_CNT];

public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	Brain& operator=(const Brain& other);
};

#endif