#include "phonebook.hpp"

Contact::Contact(void) :

	_firstName(""),
	_lastName(""),
	_nickName(""),
	_darkestSecret(""),
	_phoneNumber("") {

	std::cout << "Another Contact instance" <<  std::endl;
}

Contact::~Contact(void) {

	std::cout << "Contact instance Destroyed" <<  std::endl;
}

// Sets Contact::firstName if the string contains only letters or spaces.
// return 0 if successful, 1 if not.
int	Contact::set_firstName(string firstName) {

	//	remove starting and ending spaces
	if (trim(firstName) == "") { return (1); }
	// check for letters or spaces only
	for (size_t i = 0; i < firstName.length(); i++) {
		if (!(isalpha(firstName[i]) || firstName[i] == ' ')) { return (1); }
	}
	_firstName = firstName;
	return (0);
}

// Sets Contact::lastName if the string contains only letters or spaces.
// return 0 if successful, 1 if not.
int	Contact::set_lastName(string lastName) {

	//	remove starting and ending spaces
	if (trim(lastName) == "") { return (1); }
	// check for letters or spaces only
	for (size_t i = 0; i < lastName.length(); i++) {
		if (!(isalpha(lastName[i]) || lastName[i] == ' ')) { return (1); }
	}
	_lastName = lastName;
	return (0);
}

// Sets Contact::nickName if the string contains only letters, numbers or spaces.
// return 0 if successful, 1 if not.
int	Contact::set_nickName(string nickName) {

	//	remove starting and ending spaces
	if (trim(nickName) == "") { return (1); }
	// check for letters, numbers or spaces only
	for (size_t i = 0; i < nickName.length(); i++) {
		if (!(isalnum(nickName[i]) || nickName[i] == ' ')) { return (1); }
	}
	_nickName = nickName;
	return (0);
}

// Sets Contact::darkestScret if the string contains only printable characters.
// return 0 if successful, 1 if not.
int	Contact::set_darkestSecret(string darkestSecret) {

	//	remove starting and ending spaces
	if (trim(darkestSecret) == "") { return (1); }
	// check for printable characters only
	for (size_t i = 0; i < darkestSecret.length(); i++) {
		if (!isprint(darkestSecret[i])) { return (1); }
	}
	_darkestSecret = darkestSecret;
	return (0);
}

// Sets Contact:phoneNumber if the string contains only numbers;
// return 0 if successful, 1 if not.
int	Contact::set_phoneNumber(string phoneNumber) {

	//	remove starting and ending spaces
	if (trim(phoneNumber) == "") { return (1); }

	// remove possible starting '0' from phoneNumber
	phoneNumber.erase(0, phoneNumber.find_first_not_of('0'));
	if (phoneNumber == "") { return (1); }

	//	check for more than 10 digits
	if (phoneNumber.length() > 10) { return (1); }
	// check for digits only
	for (size_t i = 0; i < phoneNumber.length(); i++) {
		if (!isdigit(phoneNumber[i])) { return (1); }
	}
	// convert from string to unsigned long
	_phoneNumber = phoneNumber;
	std::cout << "'" << _phoneNumber << "'" << std::endl;
	return (0);
}

// I tought that 'this->' was necessary before any variable name
// since it's a pointer to the instance of the class
// (in my head nothing is automatic, Specialists call it C Language post traumatic stress)
// but you can access the instance's content just by referring its name;

// return Contact::firstName.
string	Contact::get_firstName(void) const { return (_firstName); }

// return Contact::lastName.
string	Contact::get_lastName(void) const { return (_lastName); }

// return Contact::nickName.
string	Contact::get_nickName(void) const { return (_nickName); }

// return Contact::darkestSecret.
string	Contact::get_darkestSecret(void) const { return (_darkestSecret); }

// return Contact::phoneNumber.
string	Contact::get_phoneNumber(void) const { return (_phoneNumber); }
