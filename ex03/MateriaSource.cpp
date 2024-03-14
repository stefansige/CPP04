#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	learnMateriaIndex = 0;
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource)
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	learnMateriaIndex = 0;
	*this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource)
{
	if (this == &materiaSource)
		return *this;
	learnMateriaIndex = materiaSource.learnMateriaIndex;
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
		{
			delete materias[i];
			materias[i] = NULL;
		}
		if (materiaSource.materias[i])
			materias[i] = materiaSource.materias[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i])
		{
			delete materias[i];
			materias[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (learnMateriaIndex < 4 && materia)
	{
		materias[learnMateriaIndex] = materia;
		learnMateriaIndex++;
	}
	else if (learnMateriaIndex == 4)
	{
		std::cout << "MateriaSource is full" << std::endl;
		delete materia;
		materia = NULL;
	}
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] && materias[i]->getType() == type)
		{
			return materias[i]->clone();
		}
	}
	std::cout << "Materia not found, i will crash because i dont have default materia for you friend bye" << std::endl;
	return NULL;
}

