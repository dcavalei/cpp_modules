#include "Animal.hpp"

Animal::Animal( void ) : _type("Animal") {
	std::cout << "Animal default C/tor called" << std::endl;
}

Animal::Animal( const Animal& obj ) {
	std::cout << "Animal copy C/tor called" << std::endl;
	*this = obj;
}

Animal::~Animal( void ) {
	std::cout << "Animal D/tor called" << std::endl;
}

Animal&	Animal::operator=( const Animal& rhs ) {
	std::cout << "Animal assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	return (*this);
}

void		Animal::makeSound( void ) const {
	std::cout << "Brrrrrrrrrr Brrrrr!" << std::endl;
}

std::string	Animal::get_type( void ) const {
	return (_type);
}
