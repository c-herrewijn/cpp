#include "WrongCat.h"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Constructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj)
{
    std::cout << "WrongCat Copy Constructor Called" << std::endl;
    *this = obj;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor Called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout << "WrongCat Copy Assignement Operator Called" << std::endl;
    this->type = obj.type;
    return *this;
}

void WrongCat::makeSound(void) const
{
    std::cout << "I am a Wrongcat: meoww!" << std::endl;
}
