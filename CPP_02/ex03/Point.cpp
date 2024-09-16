#include "Point.hpp"

Point::Point() : x(0), y(0) {};

Point::Point(const float new_x, const float new_y) : x(new_x), y(new_y) {};
Point::Point(const Point& other) : x(other.x), y(other.y) {};
Point::~Point() {};

float	Point::getX() const {
	return (x.toFloat());
}

float	Point::getY() const {
	return (y.toFloat());
}

Point& Point::operator=(Point& other) {
	(void)other;
	return (*this);
};
