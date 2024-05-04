Exercise 00: Create an Animal base class with a protected attribute for type. Implement derived classes Dog and Cat inheriting from Animal, setting their type attributes based on their names. Ensure both classes have a member function makeSound() that prints appropriate sounds.

Exercise 01: Add a Brain class containing an array of 100 std::strings called ideas. Have Dog and Cat classes each contain a private Brain* attribute. Upon construction, they create their Brain using new Brain() and delete it upon destruction. Test deep copying and destruction order.

Exercise 02: Modify the Animal class to make it abstract, preventing instantiation. Ensure everything still functions as before.

Exercise 03: Implement the AMateria class with necessary member functions, including a virtual clone() function. Create concrete classes Ice and Cure inheriting from AMateria with specific implementations for clone() and use(ICharacter& target). Define the ICharacter interface and implement the concrete Character class with inventory management and use functions. Finally, implement the IMateriaSource interface with learnMateria() and createMateria() functions in the concrete MateriaSource class. Test the functionality of the classes with provided code snippets and additional tests.
