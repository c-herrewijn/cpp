#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

#include <string>

class WrongAnimal {
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &obj);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &obj);

    // note: wrong animal makeSound is not virtual!
    void makeSound(void) const;
    std::string getType(void) const;

protected:
    std::string type;
};

#endif
