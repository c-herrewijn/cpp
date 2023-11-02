#ifndef WRONGCAT_H
# define WRONGCAT_H

#include <string>
#include "WrongAnimal.h"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    WrongCat(const WrongCat &obj);
    ~WrongCat();
    WrongCat &operator=(const WrongCat &obj);

    void makeSound(void) const;
};

#endif
