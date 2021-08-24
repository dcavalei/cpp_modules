#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "Zombie created '" << _name << "'" << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie destroyed '" << _name << "'" << std::endl;
}

void	Zombie::announce( void ) const {
	std::cout << _name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string name) { _name = name; }

