#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP
#include <string>

class ClapTrap
{
private:
    std::string name;
    unsigned int hitPoints;
    int energyPoints;
    int attackDamage;

public:
    ClapTrap();
    ClapTrap(const std::string &name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string &other);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void setName(std::string name);
    const std::string &getName() const;

    void setHitPoints(unsigned int v);
    unsigned int getHitPoints() const;

    void setEnergyPoints(unsigned int v);
    unsigned int getEnergyPoints() const;

    void setAttackDamage(unsigned int v);
    unsigned int getAttackDamage() const;
};

#endif