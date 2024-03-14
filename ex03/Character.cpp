#include "Character.hpp"

Character::Character() : name("default"), trashIndex(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		trash[i] = NULL;
}

Character::Character(std::string name) : name(name) , trashIndex(0)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		trash[i] = NULL;
}

Character::Character(const Character &character)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		trash[i] = NULL;
	*this = character;
}

Character &Character::operator=(const Character &character)
{
	if (this == &character)
		return *this;
	name = character.name;
	trashIndex = character.trashIndex;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
		if (character.inventory[i])
			inventory[i] = character.inventory[i]->clone();
		deleteTrash();
		if (character.trash[i])
			trash[i] = character.trash[i]->clone();
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	deleteTrash();
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			std::cout << "Equipped " << m->getType() << " to " << name << " on slot:" << i << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
	delete m;
	m = NULL;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	std::cout << "Unequipped " << inventory[idx]->getType() << " from " << name << std::endl;
	trash[trashIndex++] = inventory[idx];
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !inventory[idx])
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	inventory[idx]->use(target);
	delete inventory[idx];
	inventory[idx] = NULL;
}

void Character::deleteTrash()
{
	for (int i = 0; i < 100; i++)
	{
		if (trash[i])
		{
			delete trash[i];
			trash[i] = NULL;
		}
	}
}

