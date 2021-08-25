#include "Fixed.hpp"

Fixed::Fixed( void ) : _rawBits(0) {
	std::cout << "[DEBUG] Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src ) {
	std::cout << "[DEBUG] Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed( void ) {
	std::cout << "[DEBUG] Destructor called" << std::endl;
}


Fixed	&Fixed::operator=( Fixed const &to_assign ) {
	std::cout << "[DEBUG] Assignation operator called" << std::endl;
	_rawBits = to_assign.get_rawBits();
	return (*this);
}

int		Fixed::get_rawBits( void ) const {
	std::cout << "[DEBUG] get_rawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::set_rawBits( int n ) {
	_rawBits = n;
}
