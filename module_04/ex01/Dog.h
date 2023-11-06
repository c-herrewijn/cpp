#ifndef DOG_H
# define DOG_H

#include <string>
#include "Animal.h"

class Dog : public Animal {
public:
    Dog();
    Dog(const Dog &obj);
    ~Dog();
    Dog &operator=(const Dog &obj);

    void makeSound(void) const;
};

#endif
