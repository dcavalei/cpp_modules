#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:

		Fixed _x;
		Fixed _y;

	public:

		Point( void );
		Point( const Point &obj );
		Point( const float x, const float y );
		~Point();

		const Point&	operator=( const Point& rhs );

		Fixed	get_x( void ) const;
		Fixed	get_y( void ) const;
};

bool	bsp( const Point &p, const Point &v1, const Point &v2, const Point &v3 );
Fixed	sign( const Point &v1, const Point &v2, const Point &v3 );



#endif
