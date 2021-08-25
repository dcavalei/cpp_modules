#include "Karen.hpp"

int	main( void ) {

	Karen sheyla;

	sheyla.complain("DEBUG");
	sheyla.complain("INFO");
	sheyla.complain("WARNING");
	sheyla.complain("ERROR");

	std::cout << std::string(100, '=') << std::endl;

	sheyla.complain("DEBUG");
	sheyla.complain("DEBUG");
	sheyla.complain("DEBUG");
	sheyla.complain("DEBUG");

	std::cout << std::string(100, '=') << std::endl;

	sheyla.complain("INFO");
	sheyla.complain("INFO");
	sheyla.complain("INFO");
	sheyla.complain("INFO");

	std::cout << std::string(100, '=') << std::endl;

	sheyla.complain("WARNING");
	sheyla.complain("WARNING");
	sheyla.complain("WARNING");
	sheyla.complain("WARNING");

	std::cout << std::string(100, '=') << std::endl;

	sheyla.complain("ERROR");
	sheyla.complain("ERROR");
	sheyla.complain("ERROR");
	sheyla.complain("ERROR");

	return (0);
}