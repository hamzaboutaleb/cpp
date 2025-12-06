#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
    this->name = "Zombie";
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed" << std::endl;
}
