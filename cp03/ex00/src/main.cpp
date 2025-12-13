#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "### TESTING CONSTRUCTORS ###" << std::endl;
    ClapTrap a("Alice");
    ClapTrap b("Bob");

    std::cout << "\n### TESTING ATTACK & DAMAGE ###" << std::endl;
    a.attack("some random bandit");

    a.takeDamage(5);

    std::cout << "\n### TESTING REPAIR ###" << std::endl;
    a.beRepaired(3);

    std::cout << "\n### TESTING ENERGY DEPLETION ###" << std::endl;
    for (int i = 0; i < 11; i++)
    {
        b.attack("Dummy");
    }

    std::cout << "\n### TESTING DEATH ###" << std::endl;
    b.takeDamage(100);
    b.beRepaired(5);

    std::cout << "\n### TESTING COPY & ASSIGNMENT ###" << std::endl;
    ClapTrap c(a);

    ClapTrap d("Dave");
    d = b;

    d.attack("someone");

    std::cout << "\n### DESTRUCTORS ###" << std::endl;
    return 0;
}