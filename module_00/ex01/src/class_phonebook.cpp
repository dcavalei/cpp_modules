#include "phonebook.hpp"

Phonebook::Phonebook(void) : _index(0) {

	// std::cout << "Another Phonebook instance" <<  std::endl;
}

Phonebook::~Phonebook(void) {

	// std::cout << "Phonebook instance destroyed" <<  std::endl;
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

	std::cout << CLEAR_SCREEN;
	i = firstName;
	while (true) {

		switch (i) {

			case firstName:
				std::cout << "FIRST NAME: ";
				function = &Contact::set_firstName;
				i = lastName;
				break ;

			case lastName:
				std::cout << "LAST NAME: ";
				function = &Contact::set_lastName;
				i = nickName;
				break ;

			case nickName:
				std::cout << "NICKNAME: ";
				function = &Contact::set_nickName;
				i = darkestSecret;
				break ;

			case darkestSecret:
				std::cout << "DARKEST SECRET: ";
				function = &Contact::set_darkestSecret;
				i = phoneNumber;
				break ;

			case phoneNumber:
				std::cout << "PHONE NUMBER: ";
				function = &Contact::set_phoneNumber;
				i = -1;
				break ;

			default:
				_index = (_index + 1) % MAX_CONTACTS;
				std::cout << CLEAR_SCREEN << "SUCCESS" << std::endl;
				return (0);
		}
		while (true) {

			std::getline(std::cin, buffer);
			if (trim(buffer) == "") { continue ; }

			if (buffer == "EXIT") { return (1); }

			if ((_contact[_index].*function)(buffer))
				std::cout << "Invalid input!\n";
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

int	Phonebook::display_contacts(void) const {

	int		width = WIDTH;
	int		columns = 4;
	char	fill_char = '+';
	string	buffer;

	std::cout << CLEAR_SCREEN;
	for (int i = 0; i < MAX_CONTACTS; i++) {

		// Top line from every row
		std::cout << string((width + 1) * columns + 1, fill_char) << std::endl;

		std::cout << fill_char << std::setw(width) << i
		<< '|' << std::setw(width) << truncate_string(_contact[i].get_firstName())
		<< '|' << std::setw(width) << truncate_string(_contact[i].get_lastName())
		<< '|' << std::setw(width) << truncate_string(_contact[i].get_nickName())
		<< fill_char << std::endl;
	}
	// Bottom line
	std::cout << string((width + 1) * columns + 1, fill_char) << std::endl;
	std::cout << "Index: ";

	while (true) {

		std::getline(std::cin, buffer);
		if (trim(buffer) == "") { continue; }
		if (buffer == "EXIT") { return (1); }

		if (buffer.find_first_not_of("0123456789") != std::string::npos) {
			std::cout << "Numbers Only!" << std::endl;
		}
		else if (display_info(buffer[0] - '0')) {
			std::cout << "Invalid index!" << std::endl;
		}
		else {
			break ;
		}
	}
	return (0);
}


int	Phonebook::display_info(int index) const {

	if ((0 < index) && index >= MAX_CONTACTS) { return (1); }

	std::cout << CLEAR_SCREEN;
	if (_contact[index].get_firstName() == "")
		std::cout << "Empty contact!" << std::endl;
	else {
		std::cout << "First name: " << _contact[index].get_firstName() << std::endl;
		std::cout << "Last name: " << _contact[index].get_lastName() << std::endl;
		std::cout << "Nickname: " << _contact[index].get_nickName() << std::endl;
		std::cout << "Darkest secret: " << _contact[index].get_darkestSecret() << std::endl;
		std::cout << "Phone number: " << _contact[index].get_phoneNumber() << std::endl;
	}
	return (0);
}
