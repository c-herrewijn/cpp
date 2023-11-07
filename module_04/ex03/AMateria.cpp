#include "AMateria.h"

AMateria::AMateria() {}

AMateria::AMateria(const AMateria &obj)
{
    *this = obj;
}

AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    return *this;
}
