#ifndef MUTANTSTACK_CPP
# define MUTANTSTACK_CPP

#include "mutantstack.hpp"

template <class T>
MutantStack<T>::MutantStack() {}

template <class T>
MutantStack<T>::~MutantStack() {}

template <class T>
MutantStack<T>::MutantStack( const MutantStack<T>& other ) {
	this->c = other.c;
}

template<class T>
MutantStack<T>&	MutantStack<T>::operator=( const MutantStack<T>& other ) {
	if (this == &other)
		return *this;

	*this = other;
	return *this;
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return this->c.begin();
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return this->c.end();
}

#endif
