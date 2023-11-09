#include "AMateria.h"
#include "ICharacter.h"
#include <iostream>

AMateria::AMateria() {}
AMateria::AMateria(std::string const &type) : type(type) {};
AMateria::AMateria(const AMateria &obj) : type(obj.type) {};
AMateria::~AMateria() {}

AMateria &AMateria::operator=(const AMateria &obj)
{
    // note const attribute 'type' can not be copied!
    (void)obj;
    return *this;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    if (this->type == "ice") {
        std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<
                  std::endl;
    }
    if (this->type == "cure") {
        std::cout << "* heals " << target.getName() << "'s wounds *" <<
                  std::endl;
    }
}
