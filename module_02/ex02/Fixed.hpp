#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

// I'm using an integer type to store bits.
// The 24 left most bits represent the integral part of the number.
// The 8 right most bits represent the decimal part of the number.
class Fixed
{
	private:

		int					_rawBits;
		static const int	_fractal_bit_amount = 8;


	public:

		Fixed( void );
		Fixed( const Fixed& src );
		Fixed( const int n );
		Fixed( const float n );
		~Fixed( void );

		Fixed&	operator=( const Fixed& other);
   		Fixed&	operator++( void );
		Fixed	operator++( int );
   		Fixed&	operator--( void );
    	Fixed	operator--( int );

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		get_rawBits( void ) const;
		void	set_rawBits( int n );
};

// here says that it can't be a member function
// https://en.cppreference.com/w/cpp/language/operators
std::ostream	&operator<<( std::ostream &ostream, const Fixed &obj );











# endif
