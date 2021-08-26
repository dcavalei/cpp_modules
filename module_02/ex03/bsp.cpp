#include "Point.hpp"

bool	bsp(const Point &v1, const Point &v2, const Point &v3, const Point &p) {

	Fixed	d1 = sign(p, v1, v2);
	Fixed	d2 = sign(p, v2, v3);
	Fixed	d3 = sign(p, v3, v1);

	bool	has_neg = (d1 <= 0) || (d2 <= 0) || (d3 <= 0);
	bool	has_pos = (d1 >= 0) || (d2 >= 0) || (d3 >= 0);

    return !(has_neg && has_pos);
}

Fixed	sign(const Point &v1, const Point &v2, const Point &v3) {
	return (Fixed((v1.get_x() - v3.get_x()) * (v2.get_y() - v3.get_y()))
	- ((v2.get_x() - v3.get_x()) * (v1.get_y() - v3.get_y())));
}
