#include "AMateria.hpp"

AMateria::AMateria( void ) : _type("none") {
	std::cout << "AMateria default C/tor called" << std::endl;
}

AMateria::AMateria( const std::string& type ) : _type(type) {
	std::cout << "AMateria type C/tor called" << std::endl;
}

AMateria::AMateria( const AMateria& obj ) {
	std::cout << "AMateria copy C/tor called" << std::endl;

	*this = obj;
}

AMateria::~AMateria( void ) {
	std::cout << "AMateria D/tor called" << std::endl;
}

AMateria&	AMateria::operator=( const AMateria& rhs ) {
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	return (*this);
}

std::string	AMateria::get_type( void ) const {
	return (_type);
}
