#include "Dog.hpp"
#include "Cat.hpp"

#define AMOUNT 100

int main( void ) {
{
	std::cout << "--------------------------------" << std::endl;
	std::cout << "----------- 1st Test -----------" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	Animal	*animal[AMOUNT];

	for (int i = 0; i < AMOUNT; i++) {
		if (i % 2)
			animal[i] = new Dog;
		else
			animal[i] = new Cat;
	}

	std::cout << "--------------------------------" << std::endl;

	for (int i = 0; i < AMOUNT; i++) {
		std::cout << '|' << animal[i]->get_type() << "| ";

		animal[i]->makeSound();
		delete animal[i];

		std::cout << std::endl;
	}

	std::cout << "--------------------------------" << std::endl;
}
{
	std::cout << "----------- 2nd Test -----------" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	Animal* cat = new Cat;
	Animal* cat_1 = new Cat;
	Animal* cat_copy = new Cat(*(static_cast<Cat *>(cat)));

	std::cout << "--------------------------------" << std::endl;

	// this isn't good to do, because in this case yes i know that animal is a cat, but it could be a dog and i am type casting it to cat.
	*static_cast<Cat *>(cat) = *static_cast<Cat *>(cat_1);

	std::cout << "--------------------------------" << std::endl;

	delete cat;
	delete cat_1;
	delete cat_copy;

	std::cout << "--------------------------------" << std::endl;
}
{
	std::cout << "----------- 3rd Test -----------" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	Dog*	dog = new Dog;
	Dog*	dog_1 = new Dog;
	Dog*	dog_copy = new Dog(*dog_1);

	std::cout << "--------------------------------" << std::endl;

	*dog = *dog_1;

	std::cout << "--------------------------------" << std::endl;

	delete dog;
	delete dog_1;
	delete dog_copy;

	std::cout << "--------------------------------" << std::endl;
}
{
	std::cout << "----------- 4th Test -----------" << std::endl;
	std::cout << "--------------------------------" << std::endl;

	Animal*	cat = new Cat;
	Animal*	dog = new Dog;

	std::cout << "--------------------------------" << std::endl;

	// it uses the animal assignment operator, since they are both Animal ptrs. So it will copy only the _type
	*cat = *dog;

	std::cout << '|' << cat->get_type() << "| ";
	cat->makeSound();
	std::cout << '|' << dog->get_type() << "| ";
	dog->makeSound();

	std::cout << "--------------------------------" << std::endl;

	delete cat;
	delete dog;

	std::cout << "--------------------------------" << std::endl;
}
	// this is not allowed now since this is a pure virtual function.
	// Animal* animal = new Animal;

	return (0);
}
