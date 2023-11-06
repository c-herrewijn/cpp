#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class AAnimal {
public:
    AAnimal();
    AAnimal(std::string type);
    AAnimal(const AAnimal &obj);
    virtual ~AAnimal();
    AAnimal &operator=(const AAnimal &obj);

    std::string getType(void) const;

    virtual void makeSound(void) const = 0;
    virtual void brainDump(void) const = 0;
    virtual void updateBrain(size_t index, std::string idea) = 0;

protected:
    std::string type;
};

#endif
