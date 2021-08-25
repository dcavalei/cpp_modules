#include "HumanB.hpp"

HumanB::HumanB( std::string name, Weapon *weapon ) :
	_name(name),
	_weapon(weapon) {
		std::cout << "HumanB '" << _name << "' created" << std::endl;
}

HumanB::~HumanB( void ) {
	std::cout << "HumanB '" << _name << "' destroyed" << std::endl;
}

void	HumanB::attack( void ) const {
	if (_weapon)
		std::cout << _name << " attacks with his weapon " << _weapon->get_type() << std::endl;
	else
		std::cout << _name << " has no weapon to attack..." << std::endl;
}

void	HumanB::set_weapon( Weapon *weapon ) {
	_weapon = weapon;
}



void	HumanB::set_name( std::string string ) {
	_name = string;
}

const	std::string&	HumanB::get_name( void ) const { return (_name); }
