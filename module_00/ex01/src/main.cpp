#include "phonebook.hpp"

int main(void)
{
	std::string string;
	phonebook name(10);
	phonebook another_name;


	std::cout << name.contacts << std::endl;
	std::cout << another_name.contacts << std::endl;
	return (0);
}
