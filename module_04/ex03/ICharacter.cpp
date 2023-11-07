#include "ICharacter.h"

ICharacter::ICharacter() {}

ICharacter::ICharacter(const ICharacter &obj)
{
    *this = obj;
}

ICharacter::~ICharacter() {}

ICharacter &ICharacter::operator=(const ICharacter &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    return *this;
}
