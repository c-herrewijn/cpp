#include <Zombie.h>

int main()
{
    // creating zombies on the heap;
    Zombie *z1 = newZombie("Beatrix");
    z1->announce();
    Zombie *z2 = newZombie("Juliana");
    z2->announce();

    // creating zombies on the stack;
    Zombie z3;
    z3.announce();
    Zombie z4;
    z4.announce();

    // creating zombies of stack of other function;
    randomChump("William");   // zombies will be destoyed function termination 
    randomChump("Alexander");

    // freeing zombies on the heap
    delete z1;
    delete z2;

    return (0);  // freeing zombies on the stack
}