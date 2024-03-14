#include "AMateria.hpp"

AMateria::AMateria() : type("AMateria")
{
}

AMateria::AMateria(const AMateria &aMateria)
{
	*this = aMateria;
}

AMateria &AMateria::operator=(const AMateria &aMateria)
{
	if (this == &aMateria)
		return *this;
	type = aMateria.type;
	return *this;
}

AMateria::AMateria(std::string const &type) : type(type)
{
}

AMateria::~AMateria()
{
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}
