#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	if (this == &animal)
		return *this;
	type = animal.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}