#include "Zombie.hpp"

int	main( void ) {
	Zombie*	zombie_horde;
	int		number_of_zombies = 10;

	zombie_horde = Zombie::zombieHorde(number_of_zombies, "diogo");
	for (int i = 0; i < number_of_zombies; i++) {
		zombie_horde[i].announce();
	}
	delete[] zombie_horde;

	return (0);
}