#include "Brain.h"
#include <iostream>
#include <string>

Brain::Brain() : ideas{"first idea", "second idea"}
{
    std::cout << "Brain Constructor Called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain Copy Constructor Called" << std::endl;
    *this = obj;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
    std::cout << "Brain Copy Assignement Operator Called" << std::endl;
    for (int i=0; i<(end(this->ideas) - begin(this->ideas)); i++) {
        this->ideas[i] = obj.ideas[i];
    }
    return *this;
}

void Brain::brainDump(void) const
{
    std::cout << "braindump:" << std::endl;
    for (int i=0; i<(end(this->ideas) - begin(this->ideas)); i++) {
        if (this->ideas[i].empty() == 0) {
            std::cout << i << ": " << this->ideas[i] << std::endl;
        }
    }
}

void Brain::updateBrain(size_t index, std::string idea)
{
    if (index >= (size_t)(end(this->ideas) - begin(this->ideas))) {
        std::cout << "Error: index [" << index << "] out of range!" << std::endl;
    }
    else {
        this->ideas[index] = idea;
    }
}
