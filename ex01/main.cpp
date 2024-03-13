#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "----Test1------" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << "----Test2------" << std::endl;

	Dog a;
	Dog b;
	Dog c = a;
	b = c;

	std::cout << "----Test3------" << std::endl;

	Animal* d[100];

	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
			d[i] = new Dog();
		else
			d[i] = new Cat();
	}

	for(int z = 0; z < 100; z++)
	{
		std::cout << "Animal " << z << " is a " << d[z]->getType() << " and makes the sound: ";
		d[z]->makeSound();
		std::cout << std::endl;
	}	

	for (int y = 0; y < 100; y++)
	{
		delete d[y];
	}
	return 0;
}