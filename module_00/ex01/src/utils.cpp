#include "utils.hpp"

// Remove leading spaces from the referenced string
std::string	&ltrim(std::string &string) {

    std::size_t start = string.find_first_not_of(" \n\r\t\f\v");
	return (start == std::string::npos) ? (string = "") : (string = string.substr(start));
}

// Remove trailing spaces from the referenced string
std::string &rtrim(std::string &string) {

    std::size_t end = string.find_last_not_of(" \n\r\t\f\v");
    return ((string = string.substr(0, end + 1)));
}

// Remove leading and trailing spaces from the referenced string
std::string &trim(std::string &string) {

    return (rtrim(ltrim(string)));
}
