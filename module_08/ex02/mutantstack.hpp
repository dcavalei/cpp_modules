#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <class T>
class MutantStack : public std::stack<T> {
	public:

		typedef typename std::stack<T>::container_type::iterator	iterator;

		MutantStack<T>();
		~MutantStack<T>();
		MutantStack<T>( const MutantStack<T>& other );

		MutantStack<T>&	operator=( const MutantStack<T>& other );

		iterator	begin();
		iterator	end();
};

# include "mutantstack.cpp"

#endif
