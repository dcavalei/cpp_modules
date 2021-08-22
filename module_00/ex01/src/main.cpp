#include "phonebook.hpp"

int main(void)
{

	Phonebook	phonebook;
	string		buffer;

	while (true) {

		std::getline(std::cin, buffer);
		if (trim(buffer) == "") { continue; }
		if (buffer == "EXIT") { return (0); }
		else if (buffer == "ADD" && phonebook.add_contact()) { return (0); }
		else if (buffer == "SEARCH" && phonebook.display_contacts()) { return (0); }
	}
	return (0);
}
