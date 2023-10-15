#include <Zombie.h>
#include <iostream>

Zombie::Zombie(std::string name) : name(name) {};
Zombie::Zombie() : name("mr Default") {};

Zombie::~Zombie()
{
    std::cout << this->name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
