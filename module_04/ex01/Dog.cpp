#include "Dog.hpp"

Dog::Dog( void ) {
	std::cout << "Dog default C/tor called" << std::endl;

	_type = "Dog";
	_brain = new Brain;
}

Dog::Dog( const Dog& obj ) {
	std::cout << "Dog copy C/tor called" << std::endl;

	_brain = new Brain;
	*this = obj;
}

Dog::~Dog( void ) {
	std::cout << "Dog D/tor called" << std::endl;

	delete _brain;
}

Dog&	Dog::operator=( const Dog& rhs ) {
	std::cout << "Dog Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	*_brain = *rhs._brain;
	return (*this);
}

void	Dog::makeSound( void ) const {
	std::cout << "Woooof Woof!" << std::endl;
}
