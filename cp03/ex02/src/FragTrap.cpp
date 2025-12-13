#include <FragTrap.hpp>
#include <iostream>

FragTrap::FragTrap() : ScavTrap()
{
    std::cout << "FragTrap " << " constructed!" << std::endl;
}
FragTrap::FragTrap(const std::string &name) : ScavTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ScavTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap assignment operator called" << std::endl;

    if (this != &other)
    {
        ScavTrap::operator=(other);
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << getName() << " destroyed" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "✋ FragTrap " << getName() << " requests a high five! Give me some skin!"
              << std::endl;
}