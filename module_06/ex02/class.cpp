#include "class.hpp"

Base*	generate() {
	int	i;

	srand(time(0));
	i = rand() % 3;

	if (i == 0) {
		return new A;
	} else if (i == 1) {
		return new B;
	} else {
		return new C;
	}
}

void	identify( Base& ref ) {
	try {
		A&	tmp = dynamic_cast<A&>(ref);
		std::cout << "A" << std::endl;
	}
	catch (std::exception& e) {
		try {
			B&	tmp = dynamic_cast<B&>(ref);
			std::cout << "B" << std::endl;
		}
		catch (std::exception& e) {
			try {
				C&	tmp = dynamic_cast<C&>(ref);
				std::cout << "C" << std::endl;
			}
			catch (std::exception& e) {
				std::cout << "Never reach" << std::endl;
			}
		}
	}
}

void	identify( Base* ptr ) {
	if (A* tmp = dynamic_cast<A*>(ptr)) {
		std::cout << "A" << std::endl;
	} else if (B* tmp = dynamic_cast<B*>(ptr)) {
		std::cout << "B" << std::endl;
	} else  if (C* tmp = dynamic_cast<C*>(ptr)){
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Never reach" << std::endl;
	}
}
