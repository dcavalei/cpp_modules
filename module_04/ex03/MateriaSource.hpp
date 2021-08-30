#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {

	private:

		AMateria*	_buffer[4];

	public:
		MateriaSource( void );
		MateriaSource( const MateriaSource& obj );
		~MateriaSource( void );

		MateriaSource&		operator=( const MateriaSource& rhs );


		virtual void		learnMateria( AMateria* obj );
		virtual AMateria*	createMateria( const std::string& type );
};

#endif
