#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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

		bool	operator==( const Fixed& rhs ) const;
		bool	operator!=( const Fixed& rhs ) const;
		bool	operator< ( const Fixed& rhs ) const;
		bool	operator> ( const Fixed& rhs ) const;
		bool	operator<=( const Fixed& rhs ) const;
		bool	operator>=( const Fixed& rhs ) const;
		Fixed	operator+ ( const Fixed& rhs ) const;
		Fixed	operator- ( const Fixed& rhs ) const;
		Fixed	operator* ( const Fixed& rhs ) const;
		Fixed	operator/ ( const Fixed& rhs ) const;
		Fixed	operator+ ( void ) const;
		Fixed	operator- ( void ) const;

		static Fixed&		min( Fixed& f1, Fixed& f2 );
		static Fixed&		max( Fixed& f1, Fixed& f2 );
		static const Fixed&	min( const Fixed& f1, const Fixed& f2 );
		static const Fixed&	max( const Fixed& f1, const Fixed& f2 );

		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		get_rawBits( void ) const;
		Fixed&	set_rawBits( int n );
};

// here says that it can't be a member function
// https://en.cppreference.com/w/cpp/language/operators
std::ostream	&operator<<( std::ostream &ostream, const Fixed &obj );











# endif
