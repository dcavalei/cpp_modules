#include "Point.hpp"

// https://www.gamedev.net/forums/topic.asp?topic_id=295943
// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle

int	main( void ) {

	Point	v1( 80.0f, 80.0f );
	Point	v2( -80.0f, -80.0f );
	Point	v3( -80.0f, 80.0f );
	Point	v4( -70.0f, 0.0f );

	std::cout << "v1 ret: " << bsp(v1, v2, v3, v1) << std::endl;
	std::cout << "v2 ret: " << bsp(v1, v2, v3, v2) << std::endl;
	std::cout << "v3 ret: " << bsp(v1, v2, v3, v3) << std::endl;
	std::cout << "v4 ret: " << bsp(v1, v2, v3, v4) << std::endl;

	for ( int y = 100; y > -100; y--) {
		for ( int x = -100; x < 100; x++) {
			if (bsp(v1, v2, v3, Point((float)x, (float)y)))
				std::cout << '.';
			else
				std::cout << 'x';
		}
		std::cout << std::endl;
	}

	return (0);
}
