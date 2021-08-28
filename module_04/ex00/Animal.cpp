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

/*						Incorrect version						*/

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal") {
	std::cout << "WrongAnimal default C/tor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& obj ) {
	std::cout << "WrongAnimal copy C/tor called" << std::endl;
	*this = obj;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal D/tor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& rhs ) {
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	return (*this);
}

void		WrongAnimal::makeSound( void ) const {
	std::cout << "Brrrrrrrrrr Brrrrr!" << std::endl;
}

std::string	WrongAnimal::get_type( void ) const {
	return (_type);
}
