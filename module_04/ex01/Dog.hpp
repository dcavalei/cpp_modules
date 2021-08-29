#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		Dog( const Dog& obj );
		~Dog( void );

		Dog&			operator=( const Dog& rhs );

		virtual void	makeSound( void ) const;

	private:

		Brain*	_brain;
};

#endif
