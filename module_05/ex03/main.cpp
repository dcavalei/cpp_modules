#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main () {

	Bureaucrat	diogo("diogo", 1);
	Intern		random;
	Form*		form;

	form = random.makeForm("PresidentialPardonForm", "criminal");
	std::cout << *form << std::endl;

	diogo.signForm(*form);
	diogo.executeForm(*form);

	delete form;

	return (0);
}

