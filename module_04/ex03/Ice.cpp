#include "Ice.h"

Ice::Ice() {}

Ice::Ice(const Ice &obj)
{
    *this = obj;
}

Ice::~Ice() {}

Ice &Ice::operator=(const Ice &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    return *this;
}
