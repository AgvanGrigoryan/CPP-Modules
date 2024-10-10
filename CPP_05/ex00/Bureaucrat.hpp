#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

// exception classes
	class GradeTooHighException : std::exception { public: const char *what() const throw(); };
	class GradeTooLowException : std::exception { public: const char *what() const throw(); };

// member functions
	Bureaucrat& operator=(const Bureaucrat& other);
	void	downGrade();
	void	raiseGrade();
// getters
	std::string	getName();
	short		getGrade();

// setters
	void		setGrade(const short grade);
};

std::ostream& operator<<(std::ostream& outsteram, Bureaucrat& obj);

#endif