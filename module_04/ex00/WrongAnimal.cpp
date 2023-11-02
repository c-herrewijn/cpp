#include "WrongAnimal.h"
#include <iostream>
#include <string>

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
    *this = obj;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    this->type = obj.type;
    return *this;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal sound: auch!! I don't know what kind of animal I am!"
              <<  std::endl;
}
