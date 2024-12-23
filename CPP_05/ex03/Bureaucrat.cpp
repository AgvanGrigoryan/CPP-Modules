#include "Bureaucrat.hpp"

// exception classes
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

Bureaucrat::Bureaucrat() : _name("Unknown"){
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	setGrade(LOWEST_GRADE);
}

Bureaucrat::Bureaucrat(const std::string& name, short grade) : _name(name), _grade(LOWEST_GRADE) {
	std::cout << "Bureaucrat parameter constructor called" << std::endl;
	setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	this->setGrade(other._grade);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

// member functions
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &other)
		this->setGrade(other._grade);
	return (*this);
}

void	Bureaucrat::downGrade() {
	setGrade(_grade + 1);
	std::cout << "Grade downed" << std::endl;
}

void	Bureaucrat::raiseGrade() {
	setGrade(_grade - 1);
	std::cout << "Grade increased" << std::endl;
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "\033[0;31m" << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
}

// getters
std::string	Bureaucrat::getName() const {
	return (_name);
}

short		Bureaucrat::getGrade() const {
	return (_grade);
}

// setters
void		Bureaucrat::setGrade(const short grade) {
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade = grade;
}

std::ostream& operator<<(std::ostream& outstream, const Bureaucrat& obj) {
	outstream << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (outstream);
}