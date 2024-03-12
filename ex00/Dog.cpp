#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &dog)
{
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	type = dog.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}