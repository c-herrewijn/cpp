#ifndef DOG_H
# define DOG_H

#include <string>
#include "Animal.h"
#include "Brain.h"

class Dog : public AAnimal {
public:
    Dog();
    Dog(const Dog &obj);
    ~Dog();
    Dog &operator=(const Dog &obj);

    void makeSound(void) const;
    void brainDump(void) const;
    void updateBrain(size_t index, std::string idea);

private:
    Brain *_brain;
};

#endif
