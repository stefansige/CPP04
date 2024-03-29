#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &cat)
{
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return *this;
	type = cat.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}