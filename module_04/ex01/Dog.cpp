#include "Dog.h"
#include "Brain.h"
#include <string>
#include <iostream>

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Constructor Called" << std::endl;
    this->_brain = new Brain();
}

Dog::Dog(const Dog &obj)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
    this->_brain = new Brain();
    *this = obj;
}

Dog::~Dog()
{
    delete this->_brain;
    std::cout << "Dog Destructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    this->type = obj.type;
    delete this->_brain;
    this->_brain = new Brain();
    *(this->_brain) = *(obj._brain);
    return *this;
}

void Dog::makeSound(void) const
{
    std::cout << "I am a Dog: meoww!" << std::endl;
}

void Dog::brainDump(void) const
{
    this->_brain->brainDump();
}

void Dog::updateBrain(size_t index, std::string idea)
{
    if (index >= (size_t)(end(this->_brain->ideas) - begin(this->_brain->ideas))) {
        std::cout << "Error: index [" << index << "] out of range!" << std::endl;
    }
    else {
        this->_brain->ideas[index] = idea;
    }
}