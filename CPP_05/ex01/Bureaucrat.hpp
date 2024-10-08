#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

#define LOWEST_GRADE 150
#define HIGHEST_GRADE 1

class Bureaucrat {
private:
	const std::string	_name;
	short				_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, short grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();

	class GradeTooHighException : std::exception {};
	class GradeTooLowException : std::exception {};

// member functions
	Bureaucrat& operator=(const Bureaucrat& other);
	void	downGrade();
	void	raiseGrade();
	void	signForm(Form& bureaucrat);

// getters
	std::string	getName() const;
	short		getGrade() const;

// setters
	void		setGrade(const short grade);
};

std::ostream& operator<<(std::ostream& outsteram, Bureaucrat& obj);

#endif