#include <Zombie.h>

Zombie *zombieHorde(int N, std::string name);

int main()
{
    Zombie *horde;
    int N = 4;

    horde = zombieHorde(N, "Musketeer");
    for (int i = 0; i < N; i++) {
        horde[i].announce();
    }
    delete [] horde;

    return (0);
}
