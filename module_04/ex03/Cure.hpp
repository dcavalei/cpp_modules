#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure( void );
		Cure( const Cure& obj );
		~Cure( void );

		Cure&				operator=( const Cure& rhs );

		virtual void 		use( ICharacter& target );
		virtual AMateria*	clone( void ) const;
};

#endif
