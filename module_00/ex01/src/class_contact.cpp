#include <phonebook.hpp>

contact::contact(void) :

	firstName(""),
	lastName(""),
	nickName(""),
	darkestSecret(""),
	phoneNumber(0) {
}

// Sets contact::firstName if the string contains only letters or spaces.
// return 0 if successful, 1 if not.
int	contact::set_firstName(string firstName) {

	// check for letters or spaces only
	for (size_t i = 0; i < firstName.length(); i++) {
		if (!(isalpha(firstName[i]) || firstName[i] == ' ')) { return (1); }
	}
	this->firstName = firstName;
	return (0);
}

// Sets contact::lastName if the string contains only letters or spaces.
// return 0 if successful, 1 if not.
int	contact::set_lastName(string lastName) {

	// check for letters or spaces only
	for (size_t i = 0; i < lastName.length(); i++) {
		if (!(isalpha(lastName[i]) || lastName[i] == ' ')) { return (1); }
	}
	this->lastName = lastName;
	return (0);
}

// Sets contact::nickName if the string contains only letters, numbers or spaces.
// return 0 if successful, 1 if not.
int	contact::set_nickName(string nickName) {

	// check for letters, numbers or spaces only
	for (size_t i = 0; i < nickName.length(); i++) {
		if (!(isalnum(nickName[i]) || nickName[i] == ' ')) { return (1); }
	}
	this->nickName = nickName;
	return (0);
}

// Sets contact::darkestScret if the string contains only printable characters.
// return 0 if successful, 1 if not.
int	contact::set_darkestSecret(string darkestSecret) {

	// check for printable characters only
	for (size_t i = 0; i < darkestSecret.length(); i++) {
		if (!isprint(darkestSecret[i])) { return (1); }
	}
	this->darkestSecret = darkestSecret;
	return (0);
}

// Sets contact:phoneNumber if the string contains only numbers, 10 digits max.
// return 0 if successful, 1 if not.
int	contact::set_phoneNumber(string phoneNumber) {

	// check for digits only
	for (int i = 0; phoneNumber.length(); i++) {
		if (!isdigit(phoneNumber[i])) { return (1); }
	}
	// remove possible starting '0' from phoneNumber
	phoneNumber.erase(0, phoneNumber.find_first_not_of('0'));

	//	check for more than 10 digits
	if (phoneNumber.length() > 10) { return (1); }

	// convert from string to unsigned long
	this->phoneNumber = std::stoul(phoneNumber);
	return (0);
}

// return contact::firstName.
string	contact::get_firstName(void) const { return (this->firstName); }

// return contact::lastName.
string	contact::get_lastName(void) const { return (this->lastName); }

// return contact::nickName.
string	contact::get_nickName(void) const { return (this->nickName); }

// return contact::darkestSecret.
string	contact::get_darkestSecret(void) const { return (this->darkestSecret); }

// return contact::phoneNumber.
ulong	contact::get_phoneNumber(void) const { return (this->phoneNumber); }
