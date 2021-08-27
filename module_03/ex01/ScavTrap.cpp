#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) {
	std::cout << "[ST] C/tor called" << std::endl;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name) {
	std::cout << "[ST] C/tor called" << std::endl;

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap( const ScavTrap& obj ) : ClapTrap(obj) {
	std::cout << "[ST] Copy C/tor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << "[ST] D/tor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=( const ScavTrap& rhs ) {
	if (this == &rhs)
		return (*this);

	_name = rhs.get_name();
	_hitPoints = rhs.get_hitPoints();
	_energyPoints = rhs.get_energyPoints();
	_attackDamage = rhs.get_attackDamage();
	return (*this);
}

void	ScavTrap::guardGate( void ) const {
	std::cout << _name << " have enterred in Gate keeper mode" << std::endl;
}
