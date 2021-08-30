#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) : _buffer() {
	std::cout << "MateriaSource default C/tor called" << std::endl;
}

MateriaSource::MateriaSource( const MateriaSource& obj ) {
	std::cout << "MateriaSource copy C/tor called" << std::endl;

	*this = obj;
}

MateriaSource::~MateriaSource( void ) {
	std::cout << "MateriaSource D/tor called" << std::endl;

	for (int i = 0; i < 4; i++) {
		if (_buffer[i])
			delete (_buffer[i]);
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& rhs ) {
	if (this == &rhs)
		return *(this);

	for (int i = 0; i < 4; i++) {
		if (rhs._buffer[i])
			_buffer[i] = rhs._buffer[i];
	}
	return (*this);
}

void			MateriaSource::learnMateria( AMateria* obj ) {
	if (!obj) {
		std::cout << "(null)" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (!_buffer[i]) {
			std::cout << obj->get_type() << " learned" << std::endl;
			_buffer[i] = obj;
			return ;
		}
	}
	std::cout << "Can't learn " << obj->get_type() << ", no space left (will delete) " << std::endl;
	delete obj;
}

AMateria*		MateriaSource::createMateria( const std::string& type ) {
	for (int i = 0; i < 4; i++) {
		if (_buffer[i] && _buffer[i]->get_type() == type) {
			return (_buffer[i]);
		}
	}
	std::cout << "Materia " << type << " not previously learned" << std::endl;
	return (0);
}
