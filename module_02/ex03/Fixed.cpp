#include "Fixed.hpp"

// #############################################################################################################################################################
// # Constructors #
// ################

Fixed::Fixed( void ) : _rawBits(0) { }
Fixed::Fixed( const Fixed& src ) {
	*this = src;
}

/*
**	here we are pushing the number 8 bits to the left and that's all we need to do
**	since an int has no fractal part (the 8 right most bits must be 0).
**	looking at this might help you to visualize it: (x == random bits)
**
**	bits before:	x 0000000 0xxxxxxx xxxxxxxx xxxxxxxx
**	bits after:		x xxxxxxx xxxxxxxx xxxxxxxx 00000000
**				   |.|....... ........ ........|........|
**					^			 ^				   ^
**				 Sign(1)  Integer part(23)	 Fractal part(8)
**
**	(yes the 0's at the left (in 'bits before:') !!MUST BE!! 0's or its out of range, undefined behaviour after that.)
*/

Fixed::Fixed( const int n ) :
	_rawBits(n << _fractal_bit_amount)
{
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
**		-we just create an int with the value = 2^8 (the '1 << _fractal_bit_amount') and we let the compiler do the appropriate bitshifting since
**			we are multiplying an int for a float, and the compiller will turn that int in to a float lets say it that way.
*/

Fixed::Fixed( const float n ) :
	_rawBits(roundf(n * (1 << _fractal_bit_amount)))
{
	if (n > (__INT_MAX__ >> 8)) {
		std::cout << "[WARNING] float " << n << " out of range(" << (__INT_MAX__ >> 8)
		<< "), undefined behaviour from now on" << std::endl;
	}
}

Fixed::~Fixed( void ) { }

// #############################################################################################################################################################
// # Operators #	https://en.cppreference.com/w/cpp/language/operators
// #############

Fixed&	Fixed::operator=( const Fixed& other ) {
	// Guard self assignment
    if (this == &other)
        return *this;
	_rawBits = other.get_rawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Fixed & obj) {
	os << obj.toFloat();
    return os;
}

// prefix increment
Fixed&	Fixed::operator++( void )
{
	_rawBits++;
	return (*this);
}

// postfix increment
Fixed	Fixed::operator++( int )
{
	Fixed old = *this;
	Fixed::operator++();
	return (old);
}

// prefiFixed decrement
Fixed&	Fixed::operator--( void )
{
	_rawBits--;
	return (*this);
}

// postfiFixed decrement
Fixed	Fixed::operator--( int )
{
	Fixed old = *this;
	operator--();
	return (old);
}

bool	Fixed::operator==( const Fixed& rhs ) const {
	return (_rawBits == rhs.get_rawBits());
}

bool	Fixed::operator!=( const Fixed& rhs ) const {
	return !(*this == rhs);
}

bool	Fixed::operator< ( const Fixed& rhs ) const {
	return (_rawBits < rhs.get_rawBits());
}

bool	Fixed::operator> ( const Fixed& rhs ) const {
	return (rhs < *this);
}

bool	Fixed::operator<=( const Fixed& rhs ) const {
	return !(*this > rhs);
}

bool	Fixed::operator>=( const Fixed& rhs ) const {
	return !(*this < rhs);
}

Fixed	Fixed::operator+ ( const Fixed& rhs ) const {
	return (Fixed().set_rawBits(this->get_rawBits() + rhs.get_rawBits()));
}

Fixed	Fixed::operator- ( const Fixed& rhs ) const {
	return (Fixed().set_rawBits(this->get_rawBits() - rhs.get_rawBits()));
}

Fixed	Fixed::operator* ( const Fixed& rhs ) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/ ( const Fixed& rhs ) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator+() const {
	return (*this);
}

Fixed	Fixed::operator-() const {
	return (-this->toFloat());
}

// #############################################################################################################################################################
// # Member functions #
// ####################

Fixed&	Fixed::min( Fixed& f1, Fixed& f2 ) {
	return ((f1 < f2) ? f1 : f2);
}

Fixed&	Fixed::max( Fixed& f1, Fixed& f2 ) {
	return ((f1 > f2) ? f1 : f2);
}

const Fixed&	Fixed::min( const Fixed& f1, const Fixed& f2 ) {
	return ((f1 < f2) ? f1 : f2);
}

const Fixed&	Fixed::max( const Fixed& f1, const Fixed& f2 ) {
	return ((f1 > f2) ? f1 : f2);
}

float	Fixed::toFloat( void ) const {
	return ((float)_rawBits / (float)(1 << _fractal_bit_amount));
}

int		Fixed::toInt( void ) const {
	return (_rawBits >> 8);
}

int		Fixed::get_rawBits( void ) const {
	return (_rawBits);
}

Fixed&	Fixed::set_rawBits( int n ) {
	_rawBits = n;
	return(*this);
}
