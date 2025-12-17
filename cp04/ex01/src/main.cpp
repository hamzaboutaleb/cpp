#include <iostream>
#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

void test_animal_array()
{
    std::cout << "--- TEST: Array of Animals (Polymorphism & Deep Copy) ---" << std::endl;

    const int array_size = 4;
    Animal *animals[array_size];

    std::cout << "\n--- Filling array with Dogs ---" << std::endl;
    for (int i = 0; i < array_size / 2; ++i)
        animals[i] = new Dog();

    std::cout << "\n--- Filling array with Cats ---" << std::endl;
    for (int i = array_size / 2; i < array_size; ++i)
        animals[i] = new Cat();

    std::cout << "\n--- Animals make sound ---" << std::endl;
    for (int i = 0; i < array_size; ++i)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << "\n--- Testing Deep Copy for Dog ---" << std::endl;
    Dog *original_dog = new Dog();
    Dog *copied_dog = new Dog(*original_dog); // Copy Constructor

    std::cout << "Original Dog address: " << original_dog << std::endl;
    std::cout << "Copied Dog address:   " << copied_dog << std::endl;

    delete original_dog;
    std::cout << "Original Dog deleted. Copied Dog should still be valid." << std::endl;
    delete copied_dog;
    std::cout << "copied Dog deleted" << std::endl;

    std::cout << "\n--- Deleting all Animals (Must use virtual destructor) ---" << std::endl;
    for (int i = 0; i < array_size; ++i)
        delete animals[i];

    std::cout << "\n--- Array test finished ---" << std::endl;
}

int main()
{
    test_animal_array();
    return 0;
}
