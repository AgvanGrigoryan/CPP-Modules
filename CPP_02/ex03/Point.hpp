#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed const	x;
	Fixed const	y;
public:
	Point();
	Point(const Point& other);
	Point(const float x, const float y);
	~Point();

	Point& operator=(Point& other);

	float	getX() const;
	float	getY() const;
};

#endif
