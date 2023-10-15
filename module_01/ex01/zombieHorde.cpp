#include <Zombie.h>
#include <iostream>

Zombie *zombieHorde(int N, std::string name)
{
    // create array of zombies with default constructor
    Zombie *horde = new Zombie[N];

    // replace default objects with objects created by parametrized constructor
    for (int i=0; i < N; i++) {
        horde[i] = Zombie(name);
    }
    return (horde);
}
