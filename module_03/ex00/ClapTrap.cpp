#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) :
	_name(""),
	_hitPoints(0),
	_energyPoints(0),
	_attackDamage(0) {
	std::cout << "C/tor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
	std::cout << "C/tor called" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& obj ) {
	std::cout << "Copy C/tor called" << std::endl;
	*this = obj;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "D/tor called" << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& rhs ) {
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
	return (*this);
}

void	ClapTrap::attack( const std::string& target ) const {
	std::cout <<
		"ClapTrap " << _name <<
		" attack " << target <<
		", causing " << _attackDamage <<
		" points of damage!"
	<< std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	_hitPoints -= amount;

	std::cout <<
		"ClapTrap " << _name <<
		" has taken " << amount <<
		" points of damage!"
	<< std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	_hitPoints += amount;

	std::cout <<
		"ClapTrap " << _name <<
		" has gain " << amount <<
		" hit points!"
	<< std::endl;
}

ClapTrap&	ClapTrap::set_name( std::string name ) {
	_name = name;
	return (*this);
}

ClapTrap&	ClapTrap::set_hitPoints( int n ) {
	_hitPoints = n;
	return (*this);
}

ClapTrap&	ClapTrap::set_energyPoints( int n ) {
	_energyPoints = n;
	return (*this);
}

ClapTrap&	ClapTrap::set_attackDamage( unsigned int n ) {
	_attackDamage = n;
	return (*this);
}


