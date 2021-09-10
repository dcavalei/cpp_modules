#ifndef ITER_HPP
# define ITER_HPP

# include <string>

template <typename T>
void	iter( T* array, std::size_t len, void (*func)(T&) );

template <typename T>
void	add_one( T& n ) { n++; }

#endif
