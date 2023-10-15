#include <Zombie.h>
#include <iostream>

Zombie::Zombie() {};
Zombie::Zombie(std::string name) : name(name) {};
Zombie::~Zombie() {};

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
