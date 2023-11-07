#include "Character.h"

Character::Character() {}

Character::Character(const Character &obj)
{
    *this = obj;
}

Character::~Character() {}

Character &Character::operator=(const Character &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    return *this;
}
