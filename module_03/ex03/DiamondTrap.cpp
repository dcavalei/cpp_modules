#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) {
	std::cout << "[DT] C/tor called" << std::endl;
}

DiamondTrap::DiamondTrap( std::string name ) :
	ClapTrap(name),
	ScavTrap(name),
	FragTrap(name),
	_name(name) {
	std::cout << "[DT] C/tor called" << std::endl;

	ScavTrap	tmp_scavTrap(name);
	FragTrap	tmp_fragTrap(name);

	ClapTrap::_name = name + ClapTrap::_name;

	_hitPoints = tmp_fragTrap.get_hitPoints();
	_energyPoints = tmp_scavTrap.get_energyPoints();
	_attackDamage = tmp_fragTrap.get_attackDamage();
	_energyPoints = ScavTrap::_energyPoints;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "[DT] D/tor called" << std::endl;
}

void		DiamondTrap::attack( std::string name ) const {
	ScavTrap::attack(name);
}

void		DiamondTrap::whoAmI( void ) const {
	std::cout <<
		"name: " << get_name() <<
		"\nClapTrap::name: " << ClapTrap::get_name()
	<< std::endl;
}

std::string	DiamondTrap::get_name( void ) const {
	return (_name);
}
