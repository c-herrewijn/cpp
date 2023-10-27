#include <ScavTrap.h>

#include <string>
#include <iostream>

int main()
{
    std::cout << "Testing exhaustion..." << std::endl;
    ScavTrap a("Alice");
    for (int i=0; i<51; i++) {  // exhaustion after 50 actions ...
        a.attack("Monter1");
    }

    return (0);
}
