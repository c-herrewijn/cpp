#include "Character.h"

Character::Character() {}
Character::Character(std::string name) : name(name) {}

Character::Character(const Character &obj)
{
    *this = obj;
}

Character::~Character() {}

Character &Character::operator=(const Character &obj)
{
    this->name = obj.name;
    return *this;
}

std::string const &Character::getName() const
{
    return this->name;
}
