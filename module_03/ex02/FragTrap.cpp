#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
	std::cout << "[FT] C/tor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name) {
	std::cout << "[FT] C/tor called" << std::endl;

	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap& obj ) : ClapTrap(obj) {
	std::cout << "[FT] Copy C/tor called" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "[FT] D/tor called" << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& rhs ) {
	if (this == &rhs)
		return (*this);

	_name = rhs.get_name();
	_hitPoints = rhs.get_hitPoints();
	_energyPoints = rhs.get_energyPoints();
	_attackDamage = rhs.get_attackDamage();
	return (*this);
}

void	FragTrap::highFivesGuys( void ) const {
	std::cout << _name << " Resquest an high five!" << std::endl;
}
