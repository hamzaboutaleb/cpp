#include <Animal.hpp>
#include <iostream>

Animal::Animal()
{
    std::cout << "Animal: Default constructor called" << std::endl;
    type = "animal";
}

Animal::~Animal()
{
    std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal: Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

const std::string Animal::getType() const
{
    return this->type;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound maybe" << std::endl;
}