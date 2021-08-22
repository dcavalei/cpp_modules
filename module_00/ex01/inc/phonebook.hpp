#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>
# include "utils.hpp"

# define MAX_CONTACTS 2
# define WIDTH 10
# define HEIGHT 20

using std::string;

class Contact {

	private:

		string	_firstName;
		string	_lastName;
		string	_nickName;
		string	_darkestSecret;
		string	_phoneNumber;

	public:

		// Constructors
		Contact(void);
		~Contact(void);

		// Setters
		int	set_firstName(string firstName);
		int	set_lastName(string lastName);
		int	set_nickName(string nickName);
		int	set_darkestSecret(string darkestSecret);
		int	set_phoneNumber(string phoneNumber);

		// Getters
		string	get_firstName(void) const;
		string	get_lastName(void) const;
		string	get_nickName(void) const;
		string	get_darkestSecret(void) const;
		string	get_phoneNumber(void) const;

};

class Phonebook {

	private:

		Contact	_contact[MAX_CONTACTS];
		int		_index;

	public:

		Phonebook(void);
		~Phonebook(void);
		int	add_contact(void);
		int	display_contacts(void);

};

#endif
