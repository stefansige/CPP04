#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog &dog)
{
	brain = new Brain(*dog.brain);
	type = dog.type;
}

Dog &Dog::operator=(const Dog &dog)
{
	if (this == &dog)
		return *this;
	Animal::operator=(dog);
	delete brain;
	brain = new Brain(*dog.brain);
	type = dog.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}