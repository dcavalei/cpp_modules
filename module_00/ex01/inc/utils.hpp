#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <iomanip>

# define CLEAR_SCREEN "\033[2J\033[1;1H"

std::string	&ltrim(std::string &string);
std::string &rtrim(std::string &string);
std::string &trim(std::string &string);

#endif