#include "Fixed.hpp"

int	main( void ) {

	Fixed	a;
	Fixed	b( a );
	Fixed	c;

	c = b;

	std::cout << a.get_rawBits() << std::endl;
	std::cout << b.get_rawBits() << std::endl;
	std::cout << c.get_rawBits() << std::endl;

	return (0);
}
