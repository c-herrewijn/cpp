#include "ICharacter.h"
#include "Character.h"
#include "AMateria.h"
#include "Ice.h"
#include "Cure.h"

#include <iostream>

static void cleanFloor()
{
    int nrSlotsFloor = sizeof(Character::floor) / sizeof(Character::floor[0]);
    for (int i=0; i<nrSlotsFloor; i++) {
        if (Character::floor[i] != NULL) {
            delete Character::floor[i];
            Character::floor[i] = NULL;
        }
    }
}

int main()
{
    ICharacter *me = new Character("Chris");
    ICharacter *harry = new Character("Harry");

    std::cout << std::endl << "-- testing Ice (copying and using)..." << std::endl;
    Ice *mi1 = new Ice();
    std::cout << "type: " << mi1->getType() << std::endl;
    mi1->use(*harry);
    Ice mi2(*mi1); // created on stack
    std::cout << "type: " << mi2.getType() << std::endl;
    mi2.use(*harry);
    AMateria *mi3 = new Ice();
    std::cout << "type: " << mi3->getType() << std::endl;
    mi3->use(*harry);
    AMateria *mi4 = mi3->clone();
    std::cout << "type: " << mi4->getType() << std::endl;
    mi4->use(*harry);
    delete mi1;
    delete mi3;
    delete mi4;

    std::cout << std::endl << "-- testing Cure (copying and using)..." << std::endl;
    Cure *mc1 = new Cure();
    std::cout << "type: " << mc1->getType() << std::endl;
    mc1->use(*harry);
    Cure mc2(*mc1); // created on stack
    std::cout << "type: " << mc2.getType() << std::endl;
    mc2.use(*harry);
    AMateria *mc3 = new Cure();
    std::cout << "type: " << mc3->getType() << std::endl;
    mc3->use(*harry);
    AMateria *mc4 = mc3->clone();
    std::cout << "type: " << mc4->getType() << std::endl;
    mc4->use(*harry);
    delete mc1;
    delete mc3;
    delete mc4;

    std::cout << std::endl << "-- testing character happy flow" << std::endl;
    me->equip(new Cure());
    me->use(0, *harry);
    me->equip(new Ice());
    me->use(1, *harry);
    me->unequip(0);
    me->unequip(1);

    std::cout << std::endl << "-- testing character edge cases" << std::endl;
    ICharacter *mrEdgeCase = new Character("Edgy Eddy");
    // applying use, when no materia are equiped
    mrEdgeCase->use(0, *harry);
    mrEdgeCase->use(42, *harry);

    // equiping too many materia
    Cure *first = new Cure();
    mrEdgeCase->equip(first);
    mrEdgeCase->equip(new Ice());
    mrEdgeCase->equip(new Cure());
    mrEdgeCase->equip(new Cure());
    Cure *tooMany = new Cure();
    mrEdgeCase->equip(tooMany);
    delete tooMany;
    // attempting to equip the same materia twice
    mrEdgeCase->equip(first);

    // illegal unequip
    mrEdgeCase->unequip(-1);
    mrEdgeCase->unequip(4);
    mrEdgeCase->unequip(1);
    mrEdgeCase->unequip(1);

    // // filling the floor
    // cleanFloor();
    // for (int i=0;i<101;i++) {
    //     mrEdgeCase->equip(new Ice());
    //     mrEdgeCase->unequip(0);
    // }
    // cleanFloor();

    std::cout << std::endl << "-- testing deep copies of Characters" << std::endl;
    Character copyHorde0 = Character("mrCopyCat");
    copyHorde0.equip(new Ice());
    copyHorde0.use(0, *harry);
    copyHorde0.use(1, *harry);
    Character copyHorde1 = Character(copyHorde0);
    copyHorde1.use(0, *harry);
    copyHorde1.use(1, *harry);

    Character copyHorde2 = Character("mrTempy");
    copyHorde2.equip(new Cure());
    copyHorde2.equip(new Cure());
    copyHorde2 = copyHorde0;
    copyHorde2.use(0, *harry);
    copyHorde2.use(1, *harry);

    // cleanup
    std::cout << std::endl << "-- cleanup" << std::endl;
    cleanFloor();
    delete harry;
    delete me;
    delete mrEdgeCase;
    return 0;
}
