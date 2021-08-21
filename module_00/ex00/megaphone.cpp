#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1) // no arguments case
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++) {
		for (int j = 0; argv[i][j]; j++) {
			std::cout << (char)std::toupper(argv[i][j]); // send to stdou
		}
	}
	std::cout << std::endl;
	return (EXIT_SUCCESS);
}
