#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <unistd.h>

// Function that replaces a certain pattern in a string <str_to_find> for another <str_to_replace>
std::string	&ft_replacePattern( std::string &str, std::string &str_to_find, std::string &str_to_replace ) {
	std::size_t	index = 0;

	if (str_to_find == "") { return (str); }

	while ((index = str.find(str_to_find, index)) != std::string::npos) {
		str.erase(index, str_to_find.length());
		str.insert(index, str_to_replace);
		index += str_to_find.length();
	}
	return (str);
}

int	main( int argc, char **argv ) {
	std::ifstream	input_fstream;
	std::ofstream	output_fstream;
	std::string		buffer;
	std::string		str_to_find;
	std::string		str_to_replace;

	if (argc != 4) {
		std::cout << "Usage: <file_name> <string_to_find> <string_to_replace>" << std::endl;
		return (1);
	}

	// File to read from
	input_fstream.open(argv[1]);
	if (!input_fstream.is_open()) {
		std::cout << "Failed to open file '" << argv[1] << '\'' << std::endl;
		return (1);
	}

	// File to write at
	output_fstream.open( std::string(argv[1]).append(".replace").c_str() );
	if (!output_fstream.is_open()) {
		input_fstream.close();
		std::cout << "Failed to create file '" << argv[1] << '\'' << std::endl;
		return (1);
	}

	str_to_find = std::string(argv[2]);
	str_to_replace = std::string(argv[3]);
	while (std::getline(input_fstream, buffer)) {
		output_fstream << ft_replacePattern(buffer, str_to_find, str_to_replace) << std::endl;
	}
	input_fstream.close();
	output_fstream.close();
	return (0);
}
