#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class AMateria {

	protected:

		std::string	_type;

	public:

		AMateria( void );
		AMateria( const std::string& type );
		AMateria( const AMateria& obj );
		~AMateria( void );

		AMateria&			operator=( const AMateria& rhs );

		virtual AMateria*	clone( void ) const = 0;
		// virtual void use(ICharacter& target);

		std::string			get_type( void ) const;
};







#endif
