#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	protected:

		ScavTrap( void );

	public:

		ScavTrap( std::string name );
		ScavTrap( const ScavTrap& obj );
		~ScavTrap( void );

		ScavTrap&	operator=( const ScavTrap& rhs );

		void		guardGate( void ) const;

};

#endif
