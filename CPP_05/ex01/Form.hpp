#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

#define FORM_LOWEST_GRADE 150
#define FORM_HIGHEST_GRADE 1


class Form {
private:
	const std::string	_name;
	const short			_gradeToSign;
	const short			_gradeToExecute;
	bool				_isSigned;

public:
// exception classes
	class GradeTooHighException : std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : std::exception {
		public:
			const char* what() const throw();
	};
// constructors
	Form();
	Form(const Form& other);
	Form(const std::string& name, short gradeToSign, short gradeToExecute);
	~Form();


// member functions
	Form&	operator=(const Form& other);
	void	beSigned(const Bureaucrat& bureaucrat);
	void	checkGrade(const short grade);

// getters
	std::string	getName() const;
	short		getGradeToSign() const;
	short		getGradeToExecute() const;
	bool		isSigned() const;
};

std::ostream& operator<<(std::ostream& outstream, const Form& form);

#endif