#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:

	int					_rawBits;
	static const int	_fractal_bit_amount = 8;


	public:

		Fixed( void );
		Fixed( Fixed const &src );
		~Fixed( void );

		Fixed	&operator=( Fixed const &to_copy);

		int		get_rawBits( void ) const;
		void	set_rawBits( int n );
};












# endif
