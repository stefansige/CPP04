#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"


#include <iostream>

int main()
{
	/*
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *zlatanIbrahimovic = new Character("Zlatan Ibrahimovic");
	me->use(0, *zlatanIbrahimovic);
	me->use(1, *zlatanIbrahimovic);
	delete zlatanIbrahimovic;
	delete me;
	delete src;
	*/
	
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	Character zlatanIbrahimovic("Zlatan Ibrahimovic");
	Character ronaldo("Ronaldo");
	Character me(ronaldo);
	zlatanIbrahimovic.equip(src->createMateria("ice"));
	zlatanIbrahimovic.equip(src->createMateria("ice"));
	zlatanIbrahimovic.equip(src->createMateria("ice"));
	zlatanIbrahimovic.equip(src->createMateria("cure"));
	zlatanIbrahimovic.equip(src->createMateria("ice"));// inventory full
	zlatanIbrahimovic.equip(src->createMateria("ice"));// inventory full
	zlatanIbrahimovic.use(0, me);
	zlatanIbrahimovic.use(1, me);
	zlatanIbrahimovic.use(2, me);
	zlatanIbrahimovic.use(3, me);
	zlatanIbrahimovic.use(4, me); // invalid index
	zlatanIbrahimovic.use(0, me); // invalid index
	zlatanIbrahimovic.equip(src->createMateria("ice"));
	zlatanIbrahimovic.equip(src->createMateria("cure"));
	zlatanIbrahimovic.use(0, me);
	zlatanIbrahimovic.unequip(0);// invalid index
	zlatanIbrahimovic.equip(src->createMateria("ice"));
	delete src;
	return 0;
}