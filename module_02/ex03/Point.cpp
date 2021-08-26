#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) { }

Point::Point( const Point &obj ) {
	*this = obj;
}

Point::Point( const float x, const float y ) : _x(x), _y(y) { }

const Point&	Point::operator=( const Point& rhs ) {
	if (this == &rhs)
		return (*this);

	_x = rhs._x;
	_y = rhs._y;
	return (*this);
}

Point::~Point( void ) { }

Fixed	Point::get_x( void ) const {
	return (_x);
}

Fixed	Point::get_y( void ) const {
	return (_y);
}
