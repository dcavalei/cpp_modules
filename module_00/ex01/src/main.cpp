#include "phonebook.hpp"

int main(void)
{

	Phonebook	phonebook;
	string		buffer;

	std::cout << CLEAR_SCREEN <<"AVAILABLE COMMANDS: <ADD> <SEARCH> <EXIT>\n" << std::endl;
	while (true) {

		std::cout << "COMMAND: ";
		std::getline(std::cin, buffer);
		if (trim(buffer) == "") { continue; }
		if (buffer == "EXIT") { return (0); }
		else if (buffer == "ADD" && phonebook.add_contact()) { return (0); }
		else if (buffer == "SEARCH" && phonebook.display_contacts()) { return (0); }
	}
	return (0);
}
