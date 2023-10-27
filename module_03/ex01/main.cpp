#include <ScavTrap.h>
#include <ClapTrap.h>

#include <string>
#include <iostream>

int main()
{
    std::cout << "Testing exhaustion..." << std::endl;
    ScavTrap a("Alice");
    for (int i=0; i<51; i++) {  // exhaustion after 50 actions ...
        a.attack("Monter1");
    }

    std::cout << "--------------" << std::endl;
    std::cout << "Testing taking damage..." << std::endl;
    ScavTrap b("Beatrix");
    b.takeDamage(30);
    b.takeDamage(30);
    b.takeDamage(30);
    b.takeDamage(30);

    std::cout << "--------------" << std::endl;
    std::cout << "Testing healing..." << std::endl;
    ScavTrap c("Christina");
    c.takeDamage(30);
    c.takeDamage(30);
    c.takeDamage(30);
    c.beRepaired(100);
    c.takeDamage(30);
    c.takeDamage(30);
    c.takeDamage(30);
    c.takeDamage(30);

    std::cout << "--------------" << std::endl;
    std::cout << "Testing extreme cases..." << std::endl;
    ScavTrap d("Diana");
    d.takeDamage(4294967295);  // max unsigned int
    std::cout << ".. testing unnecessary violence..." << std::endl;
    d.takeDamage(4294967295);  // max unsigned int
    std::cout << ".. testing impossible actions..." << std::endl;
    d.attack("Monter2");
    d.beRepaired(10);

    std::cout << "--------------" << std::endl;
    std::cout << "Testing default ScavTrap..." << std::endl;
    ScavTrap xx;
    xx.attack("Monster3");
    xx.beRepaired(10);
    // note: ScavTrap's health can be more than its initial value
    xx.takeDamage(108);

    std::cout << "--------------" << std::endl;
    std::cout << "Testing copying ScavTraps..." << std::endl;
    ScavTrap clone1("SuperClone");
    clone1.beRepaired(1000);
    ScavTrap clone2;
    clone2 = clone1;
    clone2.takeDamage(1000);
    ScavTrap clone3(clone1);
    clone3.takeDamage(1000);

    std::cout << "--------------" << std::endl;
    std::cout << "Testing guarding the gate..." << std::endl;
    clone1.guardGate();

    std::cout << "--------------" << std::endl;
    std::cout << "Testing if ClapTrap still works..." << std::endl;

    ClapTrap o("OldClapper");
    o.attack("Monster2");
    o.beRepaired(10);
    o.attack("Monster2");
    o.beRepaired(10);
    o.attack("Monster2");
    o.beRepaired(10);
    o.attack("Monster2");
    o.beRepaired(10);
    o.attack("Monster2");
    o.beRepaired(10);
    // exhausted with 60 hp
    o.attack("Monster2");
    o.beRepaired(10);

    o.takeDamage(59);
    o.takeDamage(5);
    std::cout << "--------------" << std::endl;

    return (0);
}
