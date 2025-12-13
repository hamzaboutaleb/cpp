#include "ScavTrap.hpp"
#include <iostream>

void printStats(const ScavTrap &trap)
{
    std::cout << "-> " << trap.getName() << " STATS: HP=" << trap.getHitPoints()
              << ", Energy=" << trap.getEnergyPoints()
              << ", Damage=" << trap.getAttackDamage() << "\n";
}

int main()
{
    std::cout << "--- 1. Testing ScavTrap Base Class ---\n";
    ScavTrap basic("CL4P-T");
    printStats(basic);
    basic.attack("enemy target");
    basic.takeDamage(5);
    basic.beRepaired(3);
    printStats(basic);

    std::cout << "\n--- 2. Testing ScavTrap Derived Class ---\n";
    ScavTrap awesome("FR4G-TP"); // Calls ScavTrap constructor, then sets ScavTrap stats
    printStats(awesome);

    // Testing ScavTrap's unique ability
    awesome.guardGate();

    // Testing inherited methods (Attack, TakeDamage, Repair)
    std::cout << "\n--- 3. Testing Inherited Methods ---\n";
    awesome.attack("giant boss"); // Uses ScavTrap's high damage (30)
    awesome.takeDamage(50);
    awesome.beRepaired(10);
    printStats(awesome);

    std::cout << "\n--- 4. Testing Copy and Assignment ---\n";
    ScavTrap copy_trap(awesome);
    ScavTrap assign_trap;
    assign_trap = awesome;
    printStats(copy_trap);
    printStats(assign_trap);

    std::cout << "\n--- 5. Destructors Called (Order: Assign, Copy, Awesome, Basic) ---\n";
    return 0;
}