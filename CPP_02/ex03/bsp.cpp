#include "Point.hpp"
#include <iomanip>
bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	float	ab, bc, ca;
	int		rab, rbc, rca;

	ab = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
	bc = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
	ca = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

	rab = static_cast<int>(ab);
	rbc = static_cast<int>(bc);
	rca = static_cast<int>(ca);

	if (rab == 0 || rbc == 0 || rca == 0)
		return (false);
	return ((rab < 0 && rbc < 0 && rca < 0) || (rab > 0 && rbc > 0 && rca > 0));
}
