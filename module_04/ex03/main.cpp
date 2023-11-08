#include "ICharacter.h"
#include "Character.h"
#include "AMateria.h"
#include "Ice.h"

int main()
{
    ICharacter *c = new Character("Chris");
    AMateria *i = new Ice();

    i->use(*c);

    return 0;
}
