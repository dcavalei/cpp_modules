#include "ScavTrap.hpp"

int	main( void ) {

	ScavTrap	scavTrap("<name>");
	ScavTrap	copy_scavTrap(scavTrap);


	scavTrap.attack("dog");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(25);

	scavTrap.guardGate();
	copy_scavTrap.guardGate();

	return (0);
}