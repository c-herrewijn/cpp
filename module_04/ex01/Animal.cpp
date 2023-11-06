#include "Animal.h"
#include <iostream>
#include <string>

Animal::Animal()
{
    std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal Constructor Called" << std::endl;
}

Animal::Animal(const Animal &obj)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
    *this = obj;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout << "Animal Copy Assignement Operator Called" << std::endl;
    this->type = obj.type;
    return *this;
}

std::string Animal::getType(void) const
{
    return (this->type);
}

void Animal::makeSound(void) const
{
    std::cout << "I am an unspecified animal: beep!" << std::endl;
}
