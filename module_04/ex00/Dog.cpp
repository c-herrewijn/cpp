#include "Dog.h"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    *this = obj;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    this->type = obj.type;
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "I am a dog: woof!" << std::endl;
}
