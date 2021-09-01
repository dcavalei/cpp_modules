#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int main () {

	Bureaucrat				diogo("Diogo", 1);

	Form*	tree = new ShrubberyCreationForm("Home");

	std::cout << "--------------------------------------------------------------------" << std::endl;

	std::cout << *tree << std::endl;

	std::cout << "--------------------------------------------------------------------" << std::endl;

	diogo.executeForm(*tree);
	diogo.signForm(*tree);
	diogo.executeForm(*tree);

	std::cout << "--------------------------------------------------------------------" << std::endl;


	// Bureaucrat	tmp("Diogo", -1);
	// Form		paper("paper", 10);


	// diogo.signForm(paper);



	std::cout << "--------------------------------------------------------------------" << std::endl;

	std::cout << "--------------------------------------------------------------------" << std::endl;


	delete tree;

	return (0);
}

