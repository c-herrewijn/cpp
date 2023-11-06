#include "Animal.h"
#include <iostream>
#include <string>

AAnimal::AAnimal()
{
    std::cout << "Animal Constructor Called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
    std::cout << "Animal Constructor Called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = obj;
}

AAnimal::~AAnimal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
    this->type = obj.type;
    return *this;
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}
