#ifndef MATERIASOURCE_H
# define MATERIASOURCE_H

#include "IMateriaSource.h"
#include "AMateria.h"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource &obj);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &obj);

    void learnMateria(AMateria *materiaToLearn);
    AMateria *createMateria(std::string const &type);

private:
    AMateria *memory[4];
};

#endif
