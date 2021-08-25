#include "Karen.hpp"

int	main( int argc, char **argv ) {

	if (argc != 2) { return (1); }

	Karen	sheyla;

	sheyla.filter( std::string(argv[1]) );

	return (0);
}