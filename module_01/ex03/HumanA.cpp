#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) :
	_name(name),
	_weapon(weapon) {
	std::cout << "HumanA '" << _name << "' created" << std::endl;
}

HumanA::~HumanA( void ) {
	std::cout << "HumanA '" << _name << "' destroyed" << std::endl;
}

void	HumanA::attack( void ) const {
	std::cout << _name << " attacks with his weapon " << _weapon.get_type() << std::endl;
}

void	HumanA::set_name( std::string string ) {
	_name = string;
}

const	std::string&	HumanA::get_name( void ) const { return (_name); }
