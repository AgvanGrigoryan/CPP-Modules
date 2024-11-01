#include "AForm.hpp"

// exception classes
const char* AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

AForm::AForm() : _name("Unknown_form"), _gradeToSign(FORM_LOWEST_GRADE), _gradeToExecute(FORM_LOWEST_GRADE), _isSigned(false){
	std::cout << "Form Default constructor called" << std::endl;
}

// Constructors
AForm::AForm(const std::string& name, short gradeToSign, short gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
	checkGrade(_gradeToSign);
	checkGrade(_gradeToExecute);
	std::cout << "Form parameter constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {
	std::cout << "Form copy constructor called" << std::endl;
}

AForm::~AForm() {
	std::cout << "Form destructor called" << std::endl;
}

// member functions
AForm&	AForm::operator=(const AForm& other) {
	static_cast<void>(other);
	std::cout << "Form copy assignment operator called(it doesn't do anything)" << std::endl;
	return (*this);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned == true)
		return ;
	else if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else
		_isSigned = true;	
}

void	AForm::checkGrade(const short grade) {
	if (grade > FORM_LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	else if (grade < FORM_HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
}

// getters
std::string	AForm::getName() const {
	return (_name);
}

short	AForm::getGradeToSign() const {
	return (_gradeToSign);
}

short	AForm::getGradeToExecute() const {
	return (_gradeToExecute);
}

bool	AForm::isSigned() const {
	return (_isSigned);
}


std::ostream& operator<<(std::ostream& outstream, const AForm& form) {
	std::string isFormSigned = form.isSigned() ? " is signed." : " is not signed.";
	outstream << "Form " << form.getName() << isFormSigned << '\n'
				<< "Grade needs:\n"
					<< "\t to sign - " << form.getGradeToSign() << '\n'
					<< "\t to execute - " << form.getGradeToExecute() << std::endl;
	return (outstream);
}