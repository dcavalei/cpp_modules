#ifndef ITER_HPP
# define ITER_HPP

# include <string>

template <typename T>
void	iter( T* array, std::size_t len, void (*func)(T&) );

void	add_one( int& n ) { n++; }
void	add_one( float& f ) { f++; }
void	add_one( char& c ) { c++; }







#endif
