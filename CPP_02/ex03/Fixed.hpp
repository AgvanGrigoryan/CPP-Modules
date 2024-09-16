#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	static const int	fractionalBits = 8;
	int					number;
public:
// constructors
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed& other);
	~Fixed();

// static member functions
	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

// copy assigment operator
	Fixed&	operator=(const Fixed& other);

// comparison operators
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;

// arithmetic operators
	float	operator+(const Fixed& other) const;
	float	operator-(const Fixed& other) const;
	float	operator*(const Fixed& other) const;
	float	operator/(const Fixed& other) const;

// increment & decrement (postfix)
	float	operator++(int);
	float	operator--(int);
// increment & decrement (prefix)
	float	operator++();
	float	operator--();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

};

std::ostream& operator<<(std::ostream& stream, const Fixed& FP_number);

#endif