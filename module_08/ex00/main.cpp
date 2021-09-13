#include "easyfind.hpp"
#include <vector>

int main() {

	std::vector<int> vec;

	easyFind(vec, 5);

	return 0;
}

template <typename T>
typename T::iterator	easyFind( const T &container, int n ) {

	std::T::const_iterator	it;
	std::T::const_iterator	ite;

	it = container.begin();
	ite = container.end();

    return std::find(it, ite, n);
}

