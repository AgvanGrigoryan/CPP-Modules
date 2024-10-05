#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define IDEAS_CNT 100
#define INVALID_IDX_RETURN_MSG "INDEX_NOT_FOUND"

class Brain {
private:
	std::string ideas[IDEAS_CNT];

public:
	Brain();
	Brain(const Brain& other);
	~Brain();

	bool	setIdea(unsigned int idx, const std::string& idea);
	std::string	getIdea(unsigned int idx);
	Brain& operator=(const Brain& other);
};
#endif