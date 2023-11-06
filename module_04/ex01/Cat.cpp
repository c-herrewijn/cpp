#include "Cat.h"
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat &obj)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    *this = obj;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    this->type = obj.type;
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "I am a cat: meoww!" << std::endl;
}
