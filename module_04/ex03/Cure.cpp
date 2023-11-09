#include "Cure.h"
#include "AMateria.h"

Cure::Cure() : AMateria("cure") {}
Cure::Cure(const Cure &obj) : AMateria(obj) {}
Cure::~Cure() {}

Cure &Cure::operator=(const Cure &obj)
{
    (void)obj;
    return *this;
}

AMateria *Cure::clone() const
{
    AMateria *m = new Cure();
    return m;
}
