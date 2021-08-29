#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default C/tor called" << std::endl;
}

Brain::Brain( const Brain& obj ) {
	std::cout << "Brain copy C/tor called" << std::endl;
	*this = obj;
}

Brain::~Brain( void ) {
	std::cout << "Brain D/tor called" << std::endl;
}

Brain&		Brain::operator=( const Brain& rhs ) {
	std::cout << "Brain Assignment operator called" << std::endl;
	if (this == &rhs)
		return (*this);

	for (int i = 0; i < 100; i++) {
		_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}
