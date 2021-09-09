#include "iter.hpp"
#include <iostream>

int main() {

	char	char_array[11] = "0123456789";
	int		int_array[5] = { 10, 20, 30, 40, 50 };
	float	float_array[3] = { 1.5f, 5.0f, 12.345f };


	std::cout << "char array:" << std::endl;
	for (size_t i = 0; i < 11; i++) {
		std::cout << char_array[i];
		if (i % 10) {
			std::cout << ' ';
		} else {
			std::cout << std::endl;
		}
	}
	iter<char>(char_array, 10, add_one);
	for (size_t i = 0; i < 11; i++) {
		std::cout << char_array[i] << ' ';
	}
	std::cout << std::endl;

	return 0;
}

template <typename T>
void	iter( T* array, std::size_t len, void (*func)(T&) ) {
	for (std::size_t i = 0; i < len; i++) {
			func(array[i]);
	}
}
