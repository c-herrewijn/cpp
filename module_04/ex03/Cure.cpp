#include "Cure.h"

Cure::Cure() {}

Cure::Cure(const Cure &obj)
{
    *this = obj;
}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    return *this;
}
