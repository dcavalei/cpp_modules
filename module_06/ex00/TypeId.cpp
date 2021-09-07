#include "TypeId.hpp"

TypeId::TypeId() {}
TypeId::~TypeId() {}
TypeId::TypeId( const TypeId& rhs ) { *this = rhs; }

TypeId::TypeId( const std::string& str ) : _type(_none_), _str(str) {
	if (is_special(str)) {
		_type = _special_;
	} else if (is_int(str)) {
		_type = _int_;
	} else if (is_char(str)) {
		_type = _char_;
	} else if (is_float(str)) {
		_type = _float_;
	} else if (is_double(str)) {
		_type = _double_;
	}
}

TypeId&	TypeId::operator=( const TypeId& rhs) {
	if (this == &rhs)
		return *this;

	return *this;
}

bool	TypeId::is_special( const std::string& str ) {
	std::istringstream	iss("-inf +inf nan -inff +inff nanf");
	std::string			tmp;

	while (!iss.eof()) {
		iss >> tmp;
		if (tmp == str) {
			return true;
		}
	}
	return false;
}

bool	TypeId::is_int( const std::string& str ) {
	std::istringstream	iss(str);
	int					n;

	iss >> n;
	return (iss.eof() && !iss.fail());
}

bool	TypeId::is_char( const std::string& str ) {
	return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

bool	TypeId::is_float( const std::string& str ) {
	std::istringstream	iss(str);
	float				n;
	std::string			f;

	iss >> n;
	iss >> f;
	return (f == "f" && iss.eof() && !iss.fail());
}

bool	TypeId::is_double( const std::string& str ) {
	std::istringstream	iss(str);
	double 				n;

	iss >> n;
	return (iss.eof() && !iss.fail());

}

type				TypeId::get_type() {
	return _type;
}
const std::string&	TypeId::get_string() {
	return _str;
}