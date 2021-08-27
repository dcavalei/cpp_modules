#include "ClapTrap.hpp"

int	main( void ) {

	ClapTrap	clapTrap("<name>");

	clapTrap.attack("some random dude");
	clapTrap.takeDamage(2);
	clapTrap.beRepaired(5);
	clapTrap.set_attackDamage(2);
	clapTrap.attack("some other random dude");

	return (0);
}