#include "Form.hpp"

// exception classes
const char* Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low!");
}

Form::Form() : _name("Unknown_form"), _gradeToSign(FORM_LOWEST_GRADE), _gradeToExecute(FORM_LOWEST_GRADE), _isSigned(false){
	std::cout << "Form Default constructor called" << std::endl;
}

// Constructors
Form::Form(const std::string& name, short gradeToSign, short gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
	checkGrade(_gradeToSign);
	checkGrade(_gradeToExecute);
	std::cout << "Form parameter constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute), _isSigned(other._isSigned) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

// member functions
Form&	Form::operator=(const Form& other) {
	static_cast<void>(other);
	std::cout << "Form copy assignment operator called(it doesn't do anything)" << std::endl;
	return (*this);
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (_isSigned == true)
		return ;
	else if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else
		_isSigned = true;	
}

// getters
std::string	Form::getName() const {
	return (_name);
}

short	Form::getGradeToSign() const {
	return (_gradeToSign);
}

short	Form::getGradeToExecute() const {
	return (_gradeToExecute);
}

bool	Form::isSigned() const {
	return (_isSigned);
}

// setters
void	Form::checkGrade(const short grade) {
	if (grade > FORM_LOWEST_GRADE)
		throw Form::GradeTooLowException();
	else if (grade < FORM_HIGHEST_GRADE)
		throw Form::GradeTooHighException();
}

std::ostream& operator<<(std::ostream& outstream, const Form& form) {
	std::string isFormSigned = form.isSigned() ? " is signed." : " is not signed.";
	outstream << "Form " << form.getName() << isFormSigned << '\n'
				<< "Grade needs:\n"
					<< "\t to sign - " << form.getGradeToSign() << '\n'
					<< "\t to execute - " << form.getGradeToExecute() << std::endl;
	return (outstream);
}