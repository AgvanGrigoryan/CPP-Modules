#include "Fixed.hpp"

Fixed::Fixed() : FP_number(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}
Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->FP_number = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (FP_number);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function calledh" << std::endl;
	FP_number = raw;
}