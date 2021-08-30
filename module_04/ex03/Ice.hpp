#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice( void );
		Ice( const Ice& obj );
		~Ice( void );

		Ice&				operator=( const Ice& rhs );

		virtual void 		use( ICharacter& target );
		virtual AMateria*	clone( void ) const;
};

#endif
