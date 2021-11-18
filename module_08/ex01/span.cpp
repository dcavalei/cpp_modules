#include "span.hpp"

Span::Span() {} //not usable

Span::~Span() {}

Span::Span( unsigned int n ) : _capacity(n) {}

Span::Span( const Span& other ) {
	*this = other;
}

Span&	Span::operator=( const Span& rhs ) {
	if (this == &rhs) {
		return *this;
	}

	this->_vector = rhs.get_vector();
	this->_capacity = rhs.get_capacity();

	return *this;
}

unsigned int		Span::shortestSpan() {
	std::vector<int>::iterator	it = _vector.begin();
	std::vector<int>::iterator	ite = _vector.end();
	unsigned int	sSpan = UINT_MAX;

	if (_vector.size() < 2)
		throw std::range_error("Span size < 2, can't calculate shortestSpan()");

	for (; it != (ite - 1); ++it) {
		if (static_cast<unsigned int>(*(it + 1) - *it) < sSpan)
			sSpan = *(it + 1) - *it;
	}

	return sSpan;
}

unsigned int		Span::longestSpan() {
	std::vector<int>::iterator	it = _vector.begin();
	std::vector<int>::iterator	ite = _vector.end();

	if (_vector.size() < 2)
		throw std::range_error("Span size < 2, can't calculate longestSpan()");

	return *(ite - 1) - *it;
}

const std::vector<int>&	 Span::get_vector() const {
	return _vector;
}

unsigned int			 Span::get_size() const {
	return _vector.size();
}

unsigned int			Span::get_capacity() const {
	return _capacity;
}
