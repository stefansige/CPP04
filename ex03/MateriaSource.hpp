#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria *materias[4];
	int learnMateriaIndex;
public:
	MateriaSource();
	MateriaSource(const MateriaSource &materiaSource);
	MateriaSource &operator=(const MateriaSource &materiaSource);
	~MateriaSource();
	void learnMateria(AMateria *materia);
	AMateria *createMateria(std::string const &type);
};

#endif