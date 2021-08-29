#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "Cat default C/tor called" << std::endl;

	_type = "Cat";
	_brain = new Brain;
}

Cat::Cat( const Cat& obj ) {
	std::cout << "Cat copy C/tor called" << std::endl;

	_brain = new Brain;
	*this = obj;
}

Cat::~Cat( void ) {
	std::cout << "Cat D/tor called" << std::endl;

	delete _brain;
}

Cat&	Cat::operator=( const Cat& rhs ) {
	std::cout << "Cat Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	*_brain = *rhs._brain;
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "Meow Meow!" << std::endl;
}
