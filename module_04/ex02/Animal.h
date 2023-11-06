#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal {
public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &obj);
    virtual ~Animal();
    Animal &operator=(const Animal &obj);

    virtual void makeSound(void) const;
    std::string getType(void) const;

    virtual void brainDump(void) const = 0;
    virtual void updateBrain(size_t index, std::string idea) = 0;

protected:
    std::string type;
};

#endif
