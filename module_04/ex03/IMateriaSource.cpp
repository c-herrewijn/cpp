#include "IMateriaSource.h"

IMateriaSource::IMateriaSource() {}

IMateriaSource::IMateriaSource(const IMateriaSource &obj)
{
    *this = obj;
}

IMateriaSource::~IMateriaSource() {}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    return *this;
}
