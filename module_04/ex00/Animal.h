#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>

class Animal {
public:
    Animal();
    Animal(std::string type);
    Animal(const Animal &obj);
    ~Animal();
    Animal &operator=(const Animal &obj);

    virtual void makeSound(void) const;
    std::string getType(void) const;

protected:
    std::string type;
};

#endif
