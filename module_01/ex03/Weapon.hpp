#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon {

	private:
		std::string	_type;


	public:
		Weapon( std::string name );
		~Weapon( void );
		const std::string&	get_type( void ) const ;
		void				set_type( std::string string );

};





#endif
