#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB {

	private:

		std::string	_name;
		Weapon		*_weapon;

	public:

		HumanB( std::string name, Weapon *weapon = NULL);
		~HumanB( void );
		void				set_name( std::string string );
		const std::string&	get_name( void ) const;

		void	attack( void ) const;
};

#endif
