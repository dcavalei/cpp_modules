#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	protected:
		ClapTrap( void );

		std::string		_name;
		int				_hitPoints;
		int				_energyPoints;
		unsigned int	_attackDamage;

	public:

		ClapTrap( std::string name );
		ClapTrap( const ClapTrap& obj );
		~ClapTrap( void );

		ClapTrap&		operator=( const ClapTrap& rhs );

		void			attack( const std::string& target ) const;
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );

		ClapTrap&		set_name( std::string name );
		ClapTrap&		set_hitPoints( int n );
		ClapTrap&		set_energyPoints( int n );
		ClapTrap&		set_attackDamage( unsigned int n );

		std::string		get_name( void ) const;
		int				get_hitPoints( void ) const;
		int				get_energyPoints( void ) const;
		unsigned int	get_attackDamage( void ) const;
};

#endif
