#include <Zombie.hpp>
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
    {
        std::cout << "N must be a positive number" << std::endl;
        return NULL;
    }

    Zombie *zombies = new Zombie[N];

    for (int i = 0; i < N; i++)
    {
        zombies[i].setName(name);
    }

    return zombies;
}