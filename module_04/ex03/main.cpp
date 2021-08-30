#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int	main( void ) {

	std::cout << "------------------------------------------------------------------------" << std::endl;

	ICharacter*		character = new Character("Diogo");
	ICharacter*		target = new Character("Pedro");
	IMateriaSource*	src = new MateriaSource();

	std::cout << "------------------------------------------------------------------------" << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << "------------------------------------------------------------------------" << std::endl;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(0);

	std::cout << "------------------------------------------------------------------------" << std::endl;

	std::cout << character->getName() << std::endl;

	AMateria*	tmp;

	tmp = src->createMateria("ice");
	character->equip(tmp);
	character->equip(tmp);

	tmp = src->createMateria("cure");
	character->equip(tmp);
	character->equip(tmp);

	std::cout << "------------------------------------------------------------------------" << std::endl;

	character->equip(tmp);
	tmp = src->createMateria("ice");
	character->equip(tmp);

	std::cout << "------------------------------------------------------------------------" << std::endl;

	character->unequip(1);

	character->equip(tmp);
	character->unequip(1);
	character->unequip(10);

	std::cout << "------------------------------------------------------------------------" << std::endl;

	// not protected, debug only
	// std::cout << static_cast<Character *>(character)->getInventory()[2]->get_type() << std::endl;

	character->use(0, *target);
	character->use(1, *target);
	character->use(2, *target);
	character->use(3, *target);
	character->use(6, *target);

	std::cout << "------------------------------------------------------------------------" << std::endl;

	delete character;
	delete target;
	delete src;

	std::cout << "------------------------------------------------------------------------" << std::endl;

	return (0);
}
