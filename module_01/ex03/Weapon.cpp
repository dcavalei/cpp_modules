#include "Weapon.hpp"

Weapon::Weapon( std::string name ) : _type(name) {
	std::cout << "weapon '" << name << "' created" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "weapon '" << _type << "' destroyed" << std::endl;
}

const std::string&	Weapon::get_type( void ) const { return (_type); }

void				Weapon::set_type( std::string string ) {
	_type = string;
}
