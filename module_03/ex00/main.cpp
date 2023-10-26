#include <ClapTrap.h>
#include <string>
#include <iostream>

int main()
{
    std::cout << "Testing exhaustion..." << std::endl;
    ClapTrap a("Alice");
    a.attack("Monter1");
    a.beRepaired(10);
    a.attack("Monter1");
    a.beRepaired(10);
    a.attack("Monter1");
    a.beRepaired(10);
    a.attack("Monter1");
    a.beRepaired(10);
    a.attack("Monter1");
    a.beRepaired(10);
    // exhaustion after 10 actions ...
    a.attack("Monter1");
    a.beRepaired(10);
    std::cout << "--------------" << std::endl;

    std::cout << "Testing taking damage..." << std::endl;
    ClapTrap b("Beatrix");
    b.takeDamage(3);
    b.takeDamage(3);
    b.takeDamage(3);
    b.takeDamage(3);
    std::cout << "--------------" << std::endl;

    std::cout << "Testing healing..." << std::endl;
    ClapTrap c("Christina");
    c.takeDamage(3);
    c.takeDamage(3);
    c.takeDamage(3);
    c.beRepaired(10);
    c.takeDamage(3);
    c.takeDamage(3);
    c.takeDamage(3);
    c.takeDamage(3);
    std::cout << "--------------" << std::endl;

    std::cout << "Testing extreme cases..." << std::endl;
    ClapTrap d("Diana");
    d.takeDamage(4294967295);  // max unsigned int
    std::cout << ".. testing unnecessary violence..." << std::endl;
    d.takeDamage(4294967295);  // max unsigned int
    std::cout << ".. testing impossible actions..." << std::endl;
    d.attack("Monter2");
    d.beRepaired(10);
    std::cout << "--------------" << std::endl;

    std::cout << "Testing default ClapTrap..." << std::endl;
    ClapTrap xx;
    xx.attack("Monster3");
    xx.beRepaired(10);
    
    // note: ClapTrap's health can be more than its initial value
    xx.takeDamage(12);
    std::cout << "--------------" << std::endl;
}