#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &cat)
{
	brain = new Brain(*cat.brain);
	type = cat.type;
}

Cat &Cat::operator=(const Cat &cat)
{
	if (this == &cat)
		return *this;
	Animal::operator=(cat);
	delete brain;
	brain = new Brain(*cat.brain);
	type = cat.type;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete brain;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}