#ifndef CURE_H
# define CURE_H

#include "AMateria.h"

class Cure : public AMateria {
public:
    Cure();
    Cure(const Cure &obj);
    ~Cure();
    Cure &operator=(const Cure &obj);

    AMateria *clone() const;
};

#endif
