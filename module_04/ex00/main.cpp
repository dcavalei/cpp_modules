#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {

	std::cout << "\n-------------------correct version-------------------\n" << std::endl;

	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << animal->get_type() << " " << std::endl;
	std::cout << dog->get_type() << " " << std::endl;
	std::cout << cat->get_type() << " " << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	delete animal;
	delete dog;
	delete cat;

	std::cout << "\n------------------Incorrect version------------------\n" << std::endl;

	const WrongAnimal*	wrongAnimal = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << wrongAnimal->get_type() << " " << std::endl;
	std::cout << wrongCat->get_type() << " " << std::endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	delete wrongAnimal;
	delete wrongCat;

	return (0);
}
