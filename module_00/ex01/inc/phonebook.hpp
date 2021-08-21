#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cctype>

using std::string;

class Phonebook {

	private:


	public:

		Phonebook(void);
		~Phonebook(void);

};

class Contact {

	private:

		string	firstName;
		string	lastName;
		string	nickName;
		string	darkestSecret;
		ulong	phoneNumber;

	public:

		// Constructors
		Contact(void);

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
		ulong	get_phoneNumber(void) const;

};

#endif
