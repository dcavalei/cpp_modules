#include "phonebook.hpp"

Phonebook::Phonebook(void) : _index(0) {

	std::cout << "Another Phonebook instance" <<  std::endl;
}

Phonebook::~Phonebook(void) {

	std::cout << "Phonebook instance destroyed" <<  std::endl;
}


int	Phonebook::add_contact(void) {

	enum	dataMembers {
		firstName,
		lastName,
		nickName,
		darkestSecret,
		phoneNumber
	};
	string	buffer;
	int		i;
	int		(Contact::*function)(string);

	i = firstName;
	while (true) {

		switch (i) {

			case firstName:
				std::cout << "First name: ";
				function = &Contact::set_firstName;
				i = lastName;
				break ;

			case lastName:
				std::cout << "Last name: ";
				function = &Contact::set_lastName;
				i = nickName;
				break ;

			case nickName:
				std::cout << "Nickname: ";
				function = &Contact::set_nickName;
				i = darkestSecret;
				break ;

			case darkestSecret:
				std::cout << "Darkest secret: ";
				function = &Contact::set_darkestSecret;
				i = phoneNumber;
				break ;

			case phoneNumber:
				std::cout << "Phone number: ";
				function = &Contact::set_phoneNumber;
				i = -1;
				break ;

			default:
				_index = (_index + 1) % MAX_CONTACTS;
				return (0);
		}
		while (true) {

			std::getline(std::cin, buffer);
			if (trim(buffer) == "") { continue ; }

			if (buffer == "EXIT") { return (1); }

			if ((_contact[_index].*function)(buffer))
				std::cout << "Invalid input!\n try again: ";
			else
				break ;
		}
	}
	// NEVER REACH
	return (1);
}

static string	truncate_string(string string) {

	if (string.length() > 10) {

		string = string.substr(0, 10);
		string[9] = '.';
	}
	return (string);
}

int	Phonebook::display_contacts(void) {

	int		i;
	int		width = WIDTH;
	int		height = HEIGHT;
	int		columns = 4;
	char	fill_char = '+';
	i = -1;



	while (++i < MAX_CONTACTS) {

		// Top line from every row
		std::cout << string((width + 1) * columns + 1, fill_char) << std::endl;

		std::cout << fill_char << std::setw(width) << i
		<< '|' << std::setw(width) << truncate_string(_contact[i].get_firstName())
		<< '|' << std::setw(width) << truncate_string(_contact[i].get_lastName())
		<< '|' << std::setw(width) << truncate_string(_contact[i].get_nickName()) << fill_char << std::endl;
	}
	std::cout << string((width + 1) * columns + 1, fill_char) << std::endl;
	return (0);
}
