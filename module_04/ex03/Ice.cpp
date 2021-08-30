#include "Ice.hpp"

Ice::Ice( void ) {
	std::cout << "Ice default C/tor called" << std::endl;

	_type = "ice";
}

Ice::Ice( const Ice& obj ) {
	std::cout << "Ice copy C/tor called" << std::endl;

	*this = obj;
}

Ice::~Ice( void ) {
	std::cout << "Ice D/tor called" << std::endl;
}

Ice&		Ice::operator=( const Ice& rhs ) {
	std::cout << "Ice assignment operator called" << std::endl;
	if(this == &rhs)
		return (*this);

	_type = rhs.get_type();
	return (*this);
}

void		Ice::use( ICharacter& target ) {
	std::cout << "* shoots an " << get_type() << " bolt at " << target.getName() << " *" << std::endl;
}

AMateria*	Ice::clone( void ) const {
	return ( new Ice() );
}
