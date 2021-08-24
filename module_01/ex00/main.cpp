#include "Zombie.hpp"
// #include "Zombie.hpp"

int	main( void ) {
	Zombie	*zombie_heap;
	Zombie	zombie_stack;

	zombie_heap = Zombie::newZombie( "Diogo" );
	zombie_heap->announce();
	zombie_stack.announce();
	Zombie::randomChump("Joao");

	delete zombie_heap;
	return (0);
}