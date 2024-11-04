#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#define FORMS_CNT 3

typedef struct {
	std::string formName;
	AForm* (*formCreator)(const std::string& target);
} FormMapping;

class Intern {
private:
	FormMapping form_map[FORMS_CNT];

public:
	Intern();
	Intern(const Intern& other);
	~Intern();

// member functions
	Intern& operator=(const Intern& other);
	AForm*	makeForm(const std::string& formName, const std::string& target);
};

#endif