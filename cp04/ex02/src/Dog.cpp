#include <Dog.hpp>
#include <iostream>

Dog::Dog() : Animal()
{
    std::cout << "Dog: Default constructor called" << std::endl;
    type = "Dog";
    brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
    brain = new Brain();
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "Dog:: Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;

    Animal::operator=(other);
    *brain = *other.brain;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog: Destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof Woof" << std::endl;
}