#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>
# include <climits>

class Span {
	private:

		std::vector<int>	_vector;
		unsigned int		_capacity;

		Span();

	public:
		Span( unsigned int n );
		Span( const Span& other );
		~Span();

		Span&	operator=( const Span& rhs );

		template <typename T>
		void	addNumber( const T& n );
		template <typename T>
		void	addNumber( typename T::iterator itb, const typename T::iterator& ite );

		unsigned int	shortestSpan();
		unsigned int	longestSpan();

		const std::vector<int>&	get_vector() const;
		unsigned int			get_size() const;
		unsigned int			get_capacity() const;
};

template <typename T>
void	Span::addNumber( typename T::iterator itb, const typename T::iterator& ite ) {
	for (; itb != ite; ++itb) {
		addNumber(*itb);
	}
}

template <typename T>
void	Span::addNumber( const T& n) {
	if (_vector.size() < _capacity) {
		std::vector<int>::iterator upper = std::upper_bound(_vector.begin(), _vector.end(), n);
		if (upper != _vector.end()) {
			_vector.insert(upper, n);
		} else {
			_vector.push_back(n);
		}
	}
	else {
		throw std::length_error("Max capacity reached!");
	}
}

#endif