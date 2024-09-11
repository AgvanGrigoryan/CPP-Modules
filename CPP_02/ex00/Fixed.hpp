#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	static const int	bits_num = 8;
	int					FP_number;
public:
	Fixed();
	Fixed(const Fixed& other);
	~Fixed();

	Fixed&	operator=(Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif