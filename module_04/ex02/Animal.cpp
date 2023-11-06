#include "Animal.h"
#include <iostream>
#include <string>

AAnimal::AAnimal()
{
    std::cout << "AAnimal Constructor Called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
    std::cout << "AAnimal Constructor Called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
    std::cout << "AAnimal Copy Constructor Called" << std::endl;
    *this = obj;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor Called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
    std::cout << "AAnimal Copy Assignement Operator Called" << std::endl;
    this->type = obj.type;
    return *this;
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}
