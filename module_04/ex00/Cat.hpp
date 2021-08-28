#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat( void );
		Cat( const Cat& obj );
		~Cat( void );

		Cat&			operator=( const Cat& rhs );

		virtual void	makeSound( void ) const;

};

/*						Incorrect version						*/

class WrongCat : public WrongAnimal {

	public:

		WrongCat( void );
		WrongCat( const WrongCat& obj );
		~WrongCat( void );

		WrongCat&		operator=( const WrongCat& rhs );

		void			makeSound( void ) const;

};


#endif
