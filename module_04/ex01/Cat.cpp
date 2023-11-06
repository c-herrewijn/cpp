#include "Cat.h"
#include "Brain.h"
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Constructor Called" << std::endl;
    this->_brain = new Brain();
}

Cat::Cat(const Cat &obj)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    this->_brain = new Brain();
    *this = obj;
}

Cat::~Cat()
{
    delete this->_brain;
    std::cout << "Cat Destructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    std::cout << "Cat Copy Assignement Operator Called" << std::endl;
    this->type = obj.type;
    *(this->_brain) = *(obj._brain);
    return *this;
}

void Cat::makeSound(void) const
{
    std::cout << "I am a cat: meoww!" << std::endl;
}

void Cat::brainDump(void) const
{
    this->_brain->brainDump();
}

void Cat::updateBrain(size_t index, std::string idea)
{
    this->_brain->updateBrain(index, idea);
}
