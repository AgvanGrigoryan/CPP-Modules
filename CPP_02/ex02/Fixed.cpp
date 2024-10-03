#include "Fixed.hpp"
#include <climits>
#include <cmath>

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed() : number(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
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

// copy asiggment operator
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

// comparison operators
bool	Fixed::operator==(const Fixed& other) const {
	std::cout << "\033[1;33mComparison == operator called\033[0m" << std::endl;
	return (this->number == other.number);
}

bool	Fixed::operator!=(const Fixed& other) const {
	std::cout << "\033[1;33mComparison != operator called\033[0m" << std::endl;
	return !(*this == other);
}

bool	Fixed::operator>(const Fixed& other) const {
	std::cout << "\033[1;33mComparison > operator called\033[0m" << std::endl;
	return (this->number > other.number);
}

bool	Fixed::operator<(const Fixed& other) const {
	std::cout << "\033[1;33mComparison < operator called\033[0m" << std::endl;
	return (this->number < other.number);
}

bool	Fixed::operator<=(const Fixed& other) const {
	std::cout << "\033[1;33mComparison <= operator called\033[0m" << std::endl;
	return (*this < other && *this == other);
}

bool	Fixed::operator>=(const Fixed& other) const {
	std::cout << "\033[1;33mComparison >= operator called\033[0m" << std::endl;
	return (*this > other && *this == other);
}

// min max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}
// const min max
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}

// arithmetic operators
const Fixed Fixed::operator+(const Fixed& other) const {
	return (this->toFloat() + other.toFloat());
}

const Fixed Fixed::operator-(const Fixed& other) const {
	return (this->toFloat() - other.toFloat());

}

const Fixed Fixed::operator*(const Fixed& other) const {
	return (this->toFloat() * other.toFloat());
}

const Fixed Fixed::operator/(const Fixed& other) const {
	return (this->toFloat() / other.toFloat());
}

// prefix
const Fixed Fixed::operator++() {
	++this->number;
	return (*this);
}
const Fixed Fixed::operator--() {
	--this->number;
	return (*this);
}

//postfix
const Fixed Fixed::operator++(int) {
	Fixed previous_value = *this;
	++this->number;
	return (previous_value);
}
const Fixed Fixed::operator--(int) {
	Fixed previous_value = *this;
	--this->number;
	return (previous_value);
}

std::ostream& operator<<(std::ostream& stream, const Fixed& FP_number) {
	stream << FP_number.toFloat();
	return (stream);
}