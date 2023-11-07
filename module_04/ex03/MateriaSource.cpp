#include "MateriaSource.h"

MateriaSource::MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    *this = obj;
}

MateriaSource::~MateriaSource() {}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    return *this;
}
