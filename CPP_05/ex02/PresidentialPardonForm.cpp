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
	if (this == &other)
		return;
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (this->isSigned() == false) {
		std::cout << "The Form " << getName() <<  " is not signed" << std::endl;
		return;
	}
	else if (executor.getGrade() <= getGradeToExecute())
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	else
		std::cout << "Bureaucrat '" << executor.getName() << "' can not Execute the target '" << _target << "'" << std::endl;
}