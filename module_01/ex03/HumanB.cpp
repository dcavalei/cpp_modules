#include "HumanB.hpp"

HumanB::HumanB( std::string name, Weapon *weapon ) :
	_name(name),
	_weapon(weapon) {
}

HumanB::~HumanB( void ) {
	std::cout << "HumanB '" << _name << "' destroyed" << std::endl;
}

void	HumanB::attack( void ) const {
	std::cout << _name << " attacks with his weapon " << _weapon->get_type() << std::endl;
}

void	HumanB::set_name( std::string string ) {
	_name = string;
}

const	std::string&	HumanB::get_name( void ) const { return (_name); }
