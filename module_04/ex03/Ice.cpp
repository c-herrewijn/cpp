#include "Ice.h"
#include "AMateria.h"

Ice::Ice() : AMateria("ice") {}
Ice::Ice(const Ice &obj) : AMateria(obj) {}
Ice::~Ice() {}

Ice &Ice::operator=(const Ice &obj)
{
    return *this;
}

AMateria *Ice::clone() const
{
    AMateria *m = new Ice();
    return m;
}
