#include <iostream>
#include <Zombie.hpp>

int main()
{
    int N;
    std::string name;

    std::cout << "Enter N: ";
    std::cin >> N;

    std::cout << "Enter the name: ";
    std::cin >> name;

    if (name.empty() || N <= 0)
    {
        std::cout << "N must be a positive number" << std::endl;
        return 1;
    }

    Zombie *zombies = zombieHorde(N, name);

    if (zombies == NULL)
        return 1;

    for (int i = 0; i < N; i++)
    {
        zombies[i].announce();
    }

    delete[] zombies;
    return 0;
}