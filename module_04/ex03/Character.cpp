#include "Character.hpp"

Character::Character( void ) : _inventory() {
	std::cout << "Character default C/tor called" << std::endl;
}

Character::Character( std::string name ) : _name(name) {
	std::cout << "Character name C/tor called" << std::endl;
}

Character::Character( const Character& obj ) {
	std::cout << "Character copy C/tor called" << std::endl;

	*this = obj;
}

Character::~Character( void ) {
	std::cout << "Character D/tor called" << std::endl;
}

Character&				Character::operator=( const Character& rhs ) {
	std::cout << "Character assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);

	_name = rhs.getName();
	for (int i = 0; i < 4; i++) {
		_inventory[i] = rhs._inventory[i];
	}
	return (*this);
}

const AMateria* const*	Character::getInventory( void ) const {
	return (_inventory);
}

const std::string&		Character::getName( void ) const {
	return (_name);
}

void					Character::equip( AMateria* m ) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			std::cout << m->get_type() << " equiped" << std::endl;
			_inventory[i] = m;
			return;
		}
	}
	std::cout << m->get_type() << " not equiped (No space left)" << std::endl;
}

void					Character::unequip(int idx) {
	if (0 < idx && idx > 4) {
		std::cout << "4 slots only" << std::endl;
	}
	else if (_inventory[idx]) {
		std::cout << "Index " << idx << " unequiped" << std::endl;
		_inventory[idx] = 0;
	} else {
		std::cout << "Nothing to unequip" << std::endl;
	}
}

void				Character::use(int idx, ICharacter& target) {
	if (0 < idx && idx > 4)
		std::cout << "4 slots only" << std::endl;
	else if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "Empty materia, can't target " << target.getName() << std::endl;
}
