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
    this->type = obj.type;
    delete this->_brain;
    this->_brain = new Brain();
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
    if (index >= (size_t)(end(this->_brain->ideas) - begin(this->_brain->ideas))) {
        std::cout << "Error: index [" << index << "] out of range!" << std::endl;
    }
    else {
        this->_brain->ideas[index] = idea;
    }
}
