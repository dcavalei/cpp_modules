#include "iter.hpp"
#include <iostream>


template <typename T> void	output_array( const T* array, std::size_t len );
template <> void	output_array<float>( const float* array, std::size_t len );

int main() {
{
	char	array[] = "0123456789";

	std::cout << "char array: Before" << std::endl;
	output_array<char>(array, 10);
	std::cout << "---------------------------" << std::endl;

	iter<char>(array, 10, add_one);

	std::cout << "char array: After" << std::endl;
	output_array<char>(array, 10);
	std::cout << "---------------------------" << std::endl;
}
{
	int		array[5] = { 10, 20, 30, 40, 50 };

	std::cout << "int array: Before" << std::endl;
	output_array<int>(array, 5);
	std::cout << "---------------------------" << std::endl;

	iter<int>(array, 5, add_one);

	std::cout << "int array: After" << std::endl;
	output_array<int>(array, 5);
	std::cout << "---------------------------" << std::endl;
}
{
	float	array[3] = { 1.5f, 5.0f, 12.345f };


	std::cout << "float array: Before" << std::endl;
	output_array<float>(array, 3);
	std::cout << "---------------------------" << std::endl;

	iter<float>(array, 3, add_one);

	std::cout << "float array: After" << std::endl;
	output_array<float>(array, 3);
}
	return 0;
}

template <typename T>
void	iter( T* array, std::size_t len, void (*func)(T&) ) {
	for (std::size_t i = 0; i < len; i++) {
			func(array[i]);
	}
}

template <typename T>
void	output_array( const T* array, std::size_t len ) {
	for (std::size_t i = 0; i < len; i++) {
		std::cout << array[i];
		if ((i + 1) % len) {
			std::cout << ' ';
		} else {
			std::cout << std::endl;
		}
	}
}

template <>
void	output_array<float>( const float* array, std::size_t len ) {
	for (std::size_t i = 0; i < len; i++) {
		std::cout << std::fixed << array[i];
		if ((i + 1) % len) {
			std::cout << ' ';
		} else {
			std::cout << std::endl;
		}
	}
}
