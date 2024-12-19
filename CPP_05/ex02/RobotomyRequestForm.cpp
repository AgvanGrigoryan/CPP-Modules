#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", ROBOTOMYREQUEST_TOSIGN_GRADE, ROBOTOMYREQUEST_TOEXEC_GRADE), _target("_NO_TARGET_") {
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", ROBOTOMYREQUEST_TOSIGN_GRADE, ROBOTOMYREQUEST_TOEXEC_GRADE), _target(target) {
	std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// member functions
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "RobotomyRequestForm copy assignment operator called(it doesn't do anything)" << std::endl;
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	validateExecutionRequirements(executor); // Check the conditions, throw exceptions if necessary

	// Do actions of form if the checks are passed
	std::cout << "* Drilling noises *" << std::endl;

	if (rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	}
	else {
		std::cout << "The robotomy failed" << std::endl;
	}
}