#include "Karen.hpp"

Karen::Karen( void ) {
	_fArray[0] = &Karen::debug;
	_fArray[1] = &Karen::info;
	_fArray[2] = &Karen::warning;
	_fArray[3] = &Karen::error;
	std::cout << "Karen created" << std::endl;
}

Karen::~Karen( void ) {
	std::cout << "Karen destroyed" << std::endl;
}

void	Karen::debug( void ) {
	std::cout <<
		"I love to get extra baconfor my 7XL-double-cheese-"
		"triple-pickle-special-ketchup burger. I just love it!"
	<< std::endl;
}

void	Karen::info( void ) {
	std::cout <<
		"I cannot believe adding extrabacon cost more money."
		" You don’t put enough! If you did I would not have to askfor it!"
	<< std::endl;
}

void	Karen::warning( void ) {
	std::cout <<
		"I think I deserve to have some extra bacon for free."
		" I’ve beencoming here for years and you just started working here last month."
	<< std::endl;
}

void	Karen::error( void ) {
	std::cout <<
		"This is unacceptable, I want to speak to the manager now."
	<< std::endl;
}

void	Karen::complain( std::string level ) {
	std::string	string_array[4] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	for (int i = 0; i < 4; i++) {
		if (string_array[i] == level) {
			(this->*_fArray[i])();
			break ;
		}
	}
}

option	get_option( std::string level ) {
	if (level == "DEBUG") { return (DEBUG); }
	if (level == "INFO") { return (INFO); }
	if (level == "WARNING") { return (WARNING); }
	if (level == "ERROR") { return (ERROR); }
	return (INVALID);
}

void	Karen::filter( std::string level ) {
	enum option tmp;

	switch ((tmp = get_option(level)))
	{
		case DEBUG:
			std::cout << "[ DEBUG ]" << std::endl;
			complain("DEBUG");
			tmp = INFO;

		case INFO:
			std::cout << "[ INFO ]" << std::endl;
			complain("INFO");
			tmp = WARNING;

		case WARNING:
			std::cout << "[ WARNING ]" << std::endl;
			complain("WARNING");
			tmp = ERROR;

		case ERROR:
			std::cout << "[ ERROR ]" << std::endl;
			complain("ERROR");
			break;

		default:
			std::cout <<
				"[ Probably complaining about insignificant problems ]"
			<< std::endl;
			break;
	}
}


