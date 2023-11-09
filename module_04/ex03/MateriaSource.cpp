#include "MateriaSource.h"
#include "AMateria.h"

#include <iostream>

MateriaSource::MateriaSource() : memory{} {}

MateriaSource::MateriaSource(const MateriaSource &obj) : memory{}
{
    *this = obj;
}

MateriaSource::~MateriaSource()
{
    int nrSlotsMemory = sizeof(this->memory) / sizeof(this->memory[0]);
    for (int i=0; i<nrSlotsMemory; i++) {
        if (this->memory[i] != NULL) {
            delete this->memory[i];
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    int nrSlotsMemory = sizeof(this->memory) / sizeof(this->memory[0]);
    for (int i=0; i<nrSlotsMemory; i++) {
        if (obj.memory[i] != NULL) {
            this->memory[i] = obj.memory[i]->clone();
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *materiaToLearn)
{
    if (materiaToLearn == NULL) {
        std::cout << "Error: no materia to learn!" <<  std::endl;
        return ;
    }
    int nrSlotsMemory = sizeof(this->memory) / sizeof(this->memory[0]);
    bool materiaLearned = false;
    for (int i=0; i<nrSlotsMemory; i++) {
        if (this->memory[i] == NULL) {
            this->memory[i] = materiaToLearn;
            materiaLearned = true;
            std::cout << "Learned materia of type: '" << materiaToLearn->getType()
                      << "'" << std::endl;
            break;
        }
    }
    if (materiaLearned == false) {
        std::cout << "Error: could not learn Materia, memory is full!"
                  << std::endl;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int nrSlotsMemory = sizeof(this->memory) / sizeof(this->memory[0]);
    AMateria *newMateria = NULL;
    for (int i=0; i<nrSlotsMemory; i++) {
        if (this->memory[i] != NULL && this->memory[i]->getType() == type) {
            newMateria = this->memory[i]->clone();
            std::cout << "Created materia of type: '" << type << "'" << std::endl;
            break;
        }
    }
    if (newMateria == NULL) {
        std::cout << "Error: can not create materia of an type: '" << type << "'"
                  << std::endl;
    }
    return newMateria;
}
