#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default C/tor called" << std::endl;
	_type = "Dog";
}

Dog::Dog( const Dog& obj ) {
	std::cout << "Dog copy C/tor called" << std::endl;
	*this = obj;
}

Dog::~Dog( void ) {
	std::cout << "Dog D/tor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& rhs ) {
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << "Woooof Woof!" << std::endl;
}

