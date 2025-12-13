#include <ClapTrap.hpp>
#include <iostream>

ClapTrap::ClapTrap() : name("no name"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap " << name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    name = other.name;
    hitPoints = other.hitPoints;
    energyPoints = other.energyPoints;
    attackDamage = other.attackDamage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (energyPoints > 0 && hitPoints > 0)
    {
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy or health left to attack!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }

    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints -= amount;

    std::cout << "ClapTrap " << name << " took " << amount
              << " damage! Current HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints < 0 || hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy or health to repair!" << std::endl;
        return;
    }
    energyPoints--;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount
              << " points! Current HP: " << hitPoints << std::endl;
}

void ClapTrap::setHitPoints(unsigned int v)
{
    this->hitPoints = v;
}

unsigned int ClapTrap::getHitPoints() const
{
    return (this->hitPoints);
}

void ClapTrap::setEnergyPoints(unsigned int v)
{
    this->energyPoints = v;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return (this->energyPoints);
}

void ClapTrap::setAttackDamage(unsigned int v)
{
    this->attackDamage = v;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return (this->attackDamage);
}

void ClapTrap::setName(std::string name)
{
    this->name = name;
}
const std::string &ClapTrap::getName() const
{
    return this->name;
}