#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP
#include <ClapTrap.hpp>

class ScavTrap : public ClapTrap
{

public:
    ScavTrap(std::string name);
    ScavTrap();
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void guardGate();
};

#endif