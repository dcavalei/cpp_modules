#include "span.hpp"
#include <iostream>
#include <cstdlib>

void	print_span( const Span& s ) {
	for (std::size_t i = 0; i < s.get_size(); i++) {
		std::cout << "index[" << i << "] = " << s.get_vector()[i] << std::endl;
	}
}

int main() {
{
	Span span(10);

	try {
		std::cout << span.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << span.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	srand(time(0));
	for (size_t i = 0; i < 10; i++) {
		span.addNumber(rand() % 100);
	}

	print_span(span);

	std::cout << "------------------------------------" << std::endl;

	std::cout << "shortestSpan-> " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan-> " << span.longestSpan() << std::endl;
}
{
	Span				span(100);
	std::vector<int>	vector;

	for (std::size_t i = 0; i < 100; i++) {
		vector.push_back(rand() % 1000);
	}

	span.addNumber< std::vector<int> >(vector.begin(), vector.end());

	print_span(span);

	std::cout << "------------------------------------" << std::endl;

	std::cout << "shortestSpan-> " << span.shortestSpan() << std::endl;
	std::cout << "longestSpan-> " << span.longestSpan() << std::endl;
}
	return 0;
}
