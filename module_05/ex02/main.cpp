#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main () {

	Bureaucrat	diogo("Diogo", 1);
	Bureaucrat	lowLife("Some random Bureaucrat", 150);

	Form*		tree = new ShrubberyCreationForm("Home");
	Form*		robot = new RobotomyRequestForm("Dog");
	Form*		criminal = new PresidentialPardonForm("Thug");

	std::cout << "--------------------------------------------------------------------" << std::endl;

	std::cout << *tree << std::endl;
	std::cout << *robot << std::endl;
	std::cout << *criminal << std::endl;


	std::cout << "--------------------------------------------------------------------" << std::endl;

	diogo.executeForm(*tree);
	diogo.executeForm(*robot);
	diogo.executeForm(*criminal);

	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	diogo.signForm(*tree);
	diogo.executeForm(*tree);

	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	diogo.signForm(*robot);
	diogo.executeForm(*robot);

	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	diogo.signForm(*criminal);
	diogo.executeForm(*criminal);

	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	lowLife.executeForm(*tree);
	lowLife.executeForm(*robot);
	lowLife.executeForm(*criminal);

	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	(*tree).set_signed(false);
	std::cout << "[DEGUG] (*tree).set_signed(false);" << std::endl;
	(*robot).set_signed(false);
	std::cout << "[DEGUG] (*robot).set_signed(false);" << std::endl;
	(*criminal).set_signed(false);
	std::cout << "[DEGUG] (*criminal).set_signed(false);" << std::endl;

	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	lowLife.executeForm(*tree);
	lowLife.executeForm(*robot);
	lowLife.executeForm(*criminal);

	std::cout << "------------------------------------------------------------------------------------" << std::endl;

	lowLife.signForm(*tree);
	lowLife.signForm(*robot);
	lowLife.signForm(*criminal);


	delete tree;
	delete robot;
	delete criminal;

	return (0);
}

