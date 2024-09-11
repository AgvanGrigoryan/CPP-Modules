#include "Fixed.hpp"
#include <climits>
#include <cmath>

Fixed::Fixed() : number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int new_value) : number(0) {
	long long int	temp;

	temp = new_value * (1<<fractionalBits);

	if (temp > INT_MAX)
		number = INT_MAX;
	else if (temp < INT_MIN)
		number = INT_MIN;
	else
		number = static_cast<int>(temp);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float new_value) : number(0) {
	long long int	temp;

	temp = roundf(new_value * (1<<fractionalBits));

	if (temp > INT_MAX)
		number = INT_MAX;
	else if (temp < INT_MIN)
		number = INT_MIN;
	else
		number = static_cast<int>(temp);
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	this->number = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const {
	return (number);
}

void	Fixed::setRawBits(int const raw) {
	number = raw;
}

float	Fixed::toFloat(void) const {
	return (static_cast<float>(number) / static_cast<float>(1<<fractionalBits));
}

int		Fixed::toInt(void) const {
	return (toFloat());
}

std::ostream& operator<<(std::ostream& stream, const Fixed& FP_number) {
	stream << FP_number.toFloat();
	return (stream);
}