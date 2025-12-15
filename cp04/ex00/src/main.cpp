#include <iostream>
#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

#include <WrongAnimal.hpp>
#include <WrongCat.hpp>

int main()
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();
    std::cout << "TEST WRONG ANIMAL" << std::endl;
    const WrongAnimal *metaWrong = new WrongAnimal();
    const WrongAnimal *iWrong = new WrongCat();
    std::cout << iWrong->getType() << " " << std::endl;
    iWrong->makeSound(); // will output the cat sound!
    metaWrong->makeSound();
    delete meta;
    delete i;
    delete j;
    delete metaWrong;
    delete iWrong;
}
