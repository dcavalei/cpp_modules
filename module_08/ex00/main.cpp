#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main() {

	std::vector<int>	vector;
	std::list<int>		list;
	std::deque<int>		deque;
	int					tmp;

	vector.push_back(0);
	vector.push_back(1);
	vector.push_back(2);

	std::cout << *easyFind(vector, 1) << std::endl;

	tmp = 10;
	if (easyFind(vector, tmp) == vector.end()) {
		std::cout << "YEP "<< tmp << " not there." << std::endl;
	}

	std::cout << "------------------------------" << std::endl;

	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	std::cout << *easyFind(list, 4) << std::endl;

	tmp = 20;
	if (easyFind(list, tmp) == list.end()) {
		std::cout << "YEP "<< tmp << " not there." << std::endl;
	}

	std::cout << "------------------------------" << std::endl;

	deque.push_back(6);
	deque.push_back(7);
	deque.push_back(8);

	std::cout << *easyFind(deque, 7) << std::endl;

	tmp = 30;
	if (easyFind(deque, tmp) == deque.end()) {
		std::cout << "YEP "<< tmp << " not there." << std::endl;
	}

	return 0;
}

// Return value:
// Iterator to the first element satisfying the condition or last if no such element is found.
template <typename T>
typename T::const_iterator	easyFind( const T& container, int n ) {

	typename T::const_iterator	it;
	typename T::const_iterator	ite;

	it = container.begin();
	ite = container.end();

    return std::find(it, ite, n);
}
