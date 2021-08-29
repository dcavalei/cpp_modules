#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

	protected:

		std::string	_type;

	public:

		Animal( void );
		Animal( const Animal& obj );
		virtual ~Animal( void );

		Animal&			operator=( const Animal& rhs );

		// this = 0 ending will make this Class abstract
		virtual void	makeSound( void ) const = 0;

		std::string		get_type( void ) const;
};

#endif
