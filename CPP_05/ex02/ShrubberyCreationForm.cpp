#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", SHRUBBERY_TOSIGN_GRADE, SHRUBBERY_TOEXEC_GRADE) {
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", SHRUBBERY_TOSIGN_GRADE, SHRUBBERY_TOEXEC_GRADE), _target(target) {
	std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
	
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// member functions
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	AForm::operator=(other);
	_target = other._target;
	std::cout << "ShrubberyCreationForm copy assignment operator called(it doesn't do anything)" << std::endl;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (this->isSigned() == false)
		std::cout << "The Form " << getName() <<  " is not signed" << std::endl;
	if (executor.getGrade() < getGradeToExecute())
		std::cout << "Bureaucrat '" << executor.getName() << "' Executed the target '" << _target << "'" << std::endl;
	else
		std::cout << "Bureaucrat '" << executor.getName() << "' can not Execute the target '" << _target << "'" << std::endl;
}