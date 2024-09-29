#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "Ice.hpp"

int main()
{
	Character* me = new Character("Agvan");
	std::cout << me->getName() << std::endl;
	me->showInventory();
	AMateria* ice = new Ice();
	AMateria* ice2 = new Ice();
	me->equip(ice);
	me->equip(ice2);
	me->equip(ice);
	me->equip(ice2);

	me->showInventory();

	// Character you;
	// you.getName();
	// you = *me;
	// you.getName();
	// you.showInventory();

	// IMateriaSource* src = new MateriaSource();

	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());
	// ICharacter* me = new Character("me");
	// AMateria* tmp;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);
	// ICharacter* bob = new Character("bob");
	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;
	// return 0;
}