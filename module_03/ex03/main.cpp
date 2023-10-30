#include <ClapTrap.h>
#include <ScavTrap.h>
#include <FragTrap.h>
#include <DiamondTrap.h>

#include <string>
#include <iostream>

// hit points:    100
// energy points: 50
// attack damage: 30
int main()
{
    std::cout << "Testing whoAmI..." << std::endl;
    DiamondTrap a1("Alex");
    a1.whoAmI();

    DiamondTrap a2("Alice");
    std::cout << "Testing exhaustion..." << std::endl;
    for (int i=0; i<51; i++) {  // exhaustion after 50 actions ...
        a2.attack("Monter1");
    }

    std::cout << "--------------" << std::endl;
    std::cout << "Testing taking damage..." << std::endl;
    DiamondTrap b("Beatrix");
    b.takeDamage(30);
    b.takeDamage(30);
    b.takeDamage(30);
    b.takeDamage(30);

    std::cout << "--------------" << std::endl;
    std::cout << "Testing healing..." << std::endl;
    DiamondTrap c("Christina");
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
    DiamondTrap d("Diana");
    d.takeDamage(4294967295);  // max unsigned int
    std::cout << ".. testing unnecessary violence..." << std::endl;
    d.takeDamage(4294967295);  // max unsigned int
    std::cout << ".. testing impossible actions..." << std::endl;
    d.attack("Monter2");
    d.beRepaired(10);

    std::cout << "--------------" << std::endl;
    std::cout << "Testing default DiamondTrap..." << std::endl;
    DiamondTrap xx;
    xx.attack("Monster3");
    xx.beRepaired(10);
    // note: DiamondTrap's health can be more than its initial value
    xx.takeDamage(108);
    xx.whoAmI();

    std::cout << "--------------" << std::endl;
    std::cout << "Testing copying DiamondTraps..." << std::endl;
    DiamondTrap clone1("SuperClone");
    clone1.beRepaired(1000);
    DiamondTrap clone2;
    clone2 = clone1;
    clone2.takeDamage(1000);
    clone2.whoAmI();
    DiamondTrap clone3(clone1);
    clone3.takeDamage(1000);
    clone3.whoAmI();

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
