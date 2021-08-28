#include "Cat.hpp"

Cat::Cat( void ) {
	std::cout << "Cat default C/tor called" << std::endl;
	_type = "Cat";
}

Cat::Cat( const Cat& obj ) {
	std::cout << "Cat copy C/tor called" << std::endl;
	*this = obj;
}

Cat::~Cat( void ) {
	std::cout << "Cat D/tor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& rhs ) {
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	return (*this);
}

void	Cat::makeSound( void ) const {
	std::cout << "Meow Meow!" << std::endl;
}

/*						Incorrect version						*/

WrongCat::WrongCat( void ) {
	std::cout << "WrongCat default C/tor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& obj ) {
	std::cout << "WrongCat copy C/tor called" << std::endl;
	*this = obj;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat D/tor called" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& rhs ) {
	if (this == &rhs)
		return (*this);

	_type = rhs.get_type();
	return (*this);
}

void	WrongCat::makeSound( void ) const {
	std::cout << "Meow Meow!" << std::endl;
}

