#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

#define FORM_LOWEST_GRADE 150
#define FORM_HIGHEST_GRADE 1


class AForm {
private:
	const std::string	_name;
	const short			_gradeToSign;
	const short			_gradeToExecute;
	bool				_isSigned;

public:
// exception classes
	class FormNotSignedException : std::exception { public: const char* what() const throw(); };
	class InsufficientGradeException : std::exception { public: const char* what() const throw(); };
	class GradeTooHighException : std::exception { public: const char* what() const throw(); };
	class GradeTooLowException : std::exception { public: const char* what() const throw(); };

// constructors
	AForm();
	AForm(const AForm& other);
	AForm(const std::string& name, short gradeToSign, short gradeToExecute);
	virtual ~AForm();


// member functions
	AForm&			operator=(const AForm& other);
	void			beSigned(const Bureaucrat& bureaucrat);
	void			checkGrade(const short grade);
	void			validateExecutionRequirements(const Bureaucrat& executor) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

// getters
	std::string	getName() const;
	short		getGradeToSign() const;
	short		getGradeToExecute() const;
	bool		isSigned() const;

};

std::ostream& operator<<(std::ostream& outstream, const AForm& form);

#endif