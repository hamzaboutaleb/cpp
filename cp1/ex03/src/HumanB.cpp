#include <HumanB.hpp>
#include <iostream>

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack()
{
    if (weapon == NULL)
    {
        std::cout << name << " has no weapon!" << std::endl;
        return;
    }
    std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}