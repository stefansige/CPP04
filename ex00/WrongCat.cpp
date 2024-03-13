#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor called" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &wrongCat)
{
	*this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	if (this == &wrongCat)
		return *this;
	type = wrongCat.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongMeow" << std::endl;
}