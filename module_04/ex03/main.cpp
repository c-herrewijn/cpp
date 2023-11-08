#include "ICharacter.h"
#include "Character.h"
#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"

#include <iostream>

int main()
{
    ICharacter *c = new Character("Chris");

    std::cout << "-- testing Ice (copying and using)..." << std::endl;
    Ice *mi1 = new Ice();
    std::cout << "type: " << mi1->getType() << std::endl;
    mi1->use(*c);
    Ice mi2(*mi1); // created on stack
    std::cout << "type: " << mi2.getType() << std::endl;
    mi2.use(*c);
    AMateria *mi3 = new Ice();
    std::cout << "type: " << mi3->getType() << std::endl;
    mi3->use(*c);
    AMateria *mi4 = mi3->clone();
    std::cout << "type: " << mi4->getType() << std::endl;
    mi4->use(*c);
    delete mi1;
    delete mi3;
    delete mi4;

    std::cout << "-- testing Cure (copying and using)..." << std::endl;
    Cure *mc1 = new Cure();
    std::cout << "type: " << mc1->getType() << std::endl;
    mc1->use(*c);
    Cure mc2(*mc1); // created on stack
    std::cout << "type: " << mc2.getType() << std::endl;
    mc2.use(*c);
    AMateria *mc3 = new Cure();
    std::cout << "type: " << mc3->getType() << std::endl;
    mc3->use(*c);
    AMateria *mc4 = mc3->clone();
    std::cout << "type: " << mc4->getType() << std::endl;
    mc4->use(*c);
    delete mc1;
    delete mc3;
    delete mc4;

    delete c;
    return 0;
}
