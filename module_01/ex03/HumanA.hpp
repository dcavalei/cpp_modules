#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {

	private:

		std::string	_name;
		Weapon		&_weapon;

	public:

		HumanA( std::string name, Weapon &weapon );
		~HumanA( void );
		void				set_name( std::string string );
		const std::string&	get_name( void ) const;

		void	attack( void ) const;
};

#endif
