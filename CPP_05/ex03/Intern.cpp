#include "Intern.hpp"

Intern::Intern() {
    form_map[0].formName = "robotomy request";
    form_map[0].formCreator = &RobotomyRequestForm::creator;
    
    form_map[1].formName = "shrubbery creation";
    form_map[1].formCreator = &ShrubberyCreationForm::creator;
    
    form_map[2].formName = "presidential pardon";
    form_map[2].formCreator = &PresidentialPardonForm::creator;

	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& other) {
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {
	std::cout << "Intern destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) {
	int form_num;

	for (form_num = 0; form_num < FORMS_CNT; form_num++) {
		if (formName == form_map[form_num].formName)
			break;
	}
	if (form_num == FORMS_CNT) {
		throw FormNotFoundException();
	}
	AForm* new_form = form_map[form_num].formCreator(target);
	std::cout << "Intern creates " << formName << std::endl;
	return (new_form);
}