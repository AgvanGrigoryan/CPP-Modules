#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", PRESIDENTIAL_TOSIGN_GRADE, PRESIDENTIAL_TOEXEC_GRADE), _target("_NO_TARGET_") {
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), _target(other._target) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", PRESIDENTIAL_TOSIGN_GRADE, PRESIDENTIAL_TOEXEC_GRADE), _target(target) {
	std::cout << "PresidentialPardonForm parameter constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// member functions
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "PresidentialPardonForm copy assignment operator called(it doesn't do anything)" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	validateExecutionRequirements(executor); // Check the conditions, throw exceptions if necessary

	// Do actions of form if the checks are passed
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

AForm*	PresidentialPardonForm::creator(const std::string& target) {
	return new PresidentialPardonForm(target);
}