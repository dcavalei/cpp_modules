#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {

	public:

		Cat( void );
		Cat( const Cat& obj );
		~Cat( void );

		Cat&			operator=( const Cat& rhs );

		// Since i'm using the C++98 std, I can't use the override keyword, so I'll leave virtual here.
		virtual void	makeSound( void ) const;

	private:

		Brain*	_brain;
};

#endif
