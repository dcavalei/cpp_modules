#include "FragTrap.hpp"

int	main( void ) {

	FragTrap	fragTrap("<name>");
	FragTrap	copy_fragTrap(fragTrap);


	fragTrap.attack("dog");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(25);

	fragTrap.highFivesGuys();
	copy_fragTrap.highFivesGuys();

	return (0);
}