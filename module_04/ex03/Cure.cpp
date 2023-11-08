#include "Cure.h"
#include "AMateria.h"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &obj)
{
    *this = obj;
}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &obj)
{
    return *this;
}

AMateria *Cure::clone() const
{
    AMateria *m = new Cure();
    return m;
}
