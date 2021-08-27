#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"


class DiamondTrap : public ScavTrap, public FragTrap{

	private:

		std::string	_name;

	protected:

		DiamondTrap( void );

	public:

		DiamondTrap( std::string name );
		DiamondTrap( const DiamondTrap& obj );
		~DiamondTrap( void );

		void		attack ( std::string name ) const;
		void		whoAmI( void ) const;

		std::string	get_name( void ) const;
};


#endif
