#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;
	std::cout << "meta->getType(): " << meta->getType() << std::endl;
	std::cout << "j->getType(): " << j->getType() << std::endl;
	std::cout << "i->getType(): " << i->getType() << std::endl;
	std::cout << std::endl;
	j->makeSound(); //will output the cat sound!
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;

	const WrongAnimal *meta2 = new WrongAnimal();
	const WrongAnimal *i2 = new WrongCat();

	std::cout << std::endl;
	std::cout << "meta2->getType(): " << meta2->getType() << std::endl;
	std::cout << "i2->getType(): " << i2->getType() << std::endl;
	std::cout << std::endl;
	i2->makeSound();
	meta2->makeSound();
	delete meta2;
	delete i2;
	return 0;
}