#include "Fixed.hpp"

// #############################################################################################################################################################
// ## Constructors ##
// ##################
Fixed::Fixed( void ) : _rawBits(0) {
	std::cout << "[DEBUG] Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) {
	std::cout << "[DEBUG] Copy constructor called" << std::endl;
	*this = src;
}

/*
**	here we are pushing the number 8 bits to the left and that's all we need to do
**	since an int has no fractal part (the 8 right most bits must be 0).
**	looking at this might help you to visualize it: (x == random bits)
**
**							  |
**							 \|/
**	bits before:	x0000000 0xxxxxxx xxxxxxxx xxxxxxxx
**	bits after:		xxxxxxxx xxxxxxxx xxxxxxxx 00000000
**					/|\						  |........| > fractal part
**					 |
**
**	(yes the 0's at the left !!MUST BE!! 0's or its out of range, undefined behaviour after that.)
*/

Fixed::Fixed( const int n ) : _rawBits(n << _fractal_bit_amount) {
	std::cout << "[DEBUG] Const int constructor called" << std::endl;
	if (n > (__INT_MAX__ >> 8)) {
		std::cout << "[WARNING] int " << n << " out of range(" << (__INT_MAX__ >> 8)
		<< "), undefined behaviour from now on" << std::endl;
	}
}

/*
**	Here we will abuse the compiler to help us push the bits to correct spot.
**	Since floats don't have a linear approach to bits like ints do, we need to do some magic 1st..
**		-when we multiply an int by 2 (number * 2) we are basically bitshifting it to the left once (number << 1)
**			so if we multiply that int by 2^8 (number * (2^8)) we are bitshifting it to the left 8 bits.
**		-we just create the int with the value = 2^8 (the '1 << _fractal_bit_amount') and we let the compiler do the appropriate bitshifting since
**			we are multiplying an int for a float, and the compiller will turn that int in to a float lets say it that way.
*/

Fixed::Fixed( const float n ) : _rawBits(roundf(n * (1 << _fractal_bit_amount))) {
	std::cout << "[DEBUG] Const float constructor called" << std::endl;
	if (n > (__INT_MAX__ >> 8)) {
		std::cout << "[WARNING] float " << n << " out of range(" << (__INT_MAX__ >> 8)
		<< "), undefined behaviour from now on" << std::endl;
	}
}

Fixed::~Fixed( void ) {
	std::cout << "[DEBUG] Destructor called" << std::endl;
}

// #############################################################################################################################################################
// # Operators ##
// ##############

Fixed&	Fixed::operator=( const Fixed& other ) {
	std::cout << "[DEBUG] Assignation operator called" << std::endl;
	// Guard self assignment
    if (this == &other)
        return *this;
	_rawBits = other.get_rawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed & obj) {
	// std::cout << "[DEBUG] Stream insertion operator called" << std::endl;
	os << obj.toFloat();
    return os;
}

/***************************/

// prefix increment
Fixed&	Fixed::operator++( void )
{
	// actual increment takes place here
	return *this; // return new value by reference
}
// postfix increment
Fixed	Fixed::operator++( int )
{
	Fixed old = *this; // copy old value
	Fixed::operator++();  // prefiFixed increment
	return old;    // return old value
}
// prefiFixed decrement
Fixed&	Fixed::operator--( void )
{
	// actual decrement takes place here
	return *this; // return new value by reference
}
// postfiFixed decrement
Fixed	Fixed::operator--( int )
{
	Fixed old = *this; // copy old value
	operator--();  // prefix decrement
	return old;    // return old value
}

/****************************/
float	Fixed::toFloat( void ) const {
	return ((float)_rawBits / (float)(1 << _fractal_bit_amount));
}

int		Fixed::toInt( void ) const {
	return (_rawBits >> 8);
}


int		Fixed::get_rawBits( void ) const {
	std::cout << "[DEBUG] get_rawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::set_rawBits( int n ) {
	_rawBits = n;
}
