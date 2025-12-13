#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- 1. Simple FragTrap Construction ---" << std::endl;
    FragTrap ft1("Alpha");

    std::cout << "\n--- 2. FragTrap Special Ability and Standard Actions ---" << std::endl;
    ft1.highFivesGuys();

    ft1.attack("The Target");
    ft1.takeDamage(50);
    ft1.beRepaired(20);

    std::cout << "Alpha's final status: HP: " << ft1.getHitPoints()
              << ", EP: " << ft1.getEnergyPoints() << std::endl;

    std::cout << "\n--- 3. Scope-based Chaining Test (ft2 is constructed and destroyed) ---" << std::endl;
    {
        FragTrap ft2("Bravo");
        ft2.highFivesGuys();
        std::cout << "   ft2 is in scope, performing actions." << std::endl;
    }
    std::cout << "\n--- 4. End of main, ft1 Destruction ---" << std::endl;

    return 0;
}
