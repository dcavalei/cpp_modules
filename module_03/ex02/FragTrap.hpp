#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	private:

		FragTrap( void );

	public:

		FragTrap( std::string name );
		FragTrap( const FragTrap& obj );
		~FragTrap( void );

		FragTrap&	operator=( const FragTrap& rhs );

		void		highFivesGuys( void ) const;

};

#endif
