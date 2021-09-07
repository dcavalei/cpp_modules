#include <iostream>
#include "TypeId.hpp"

int main( int argc, char **argv ) {

	if (argc != 2) {
		std::cerr << "Usage: ./main.out <string>" << std::endl;
		return 1;
	}

	std::string	str(argv[1]);
	TypeId		type(argv[1]);

	if (type.get_type() == _none_) {
		std::cout << "ola\n";
	}
	std::cout << "Input: " << str << std::endl << std::endl;
	std::cout << "is_int(): " << TypeId::is_int(str) << std::endl;
	std::cout << "is_char(): " << TypeId::is_char(str) << std::endl;
	std::cout << "is_float(): " << TypeId::is_float(str) << std::endl;
	std::cout << "is_double(): " << TypeId::is_double(str) << std::endl;
	std::cout << "is_special(): " << TypeId::is_special(str) << std::endl;

	std::cout << "===========================================" << std::endl;
	std::cout << std::setprecision(8) << 1.123456789123456789f << ' ' << 1.0f << std::endl;
	std::cout << "===========================================" << std::endl;

	int i = 'a' + 256;

	std::cout << i << std::endl;
	std::cout << *(reinterpret_cast<char *>(&i)) << std::endl;
	return 0;
}
