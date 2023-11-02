#ifndef CAT_H
# define CAT_H

#include <string>
#include "Animal.h"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat &obj);
    ~Cat();
    Cat &operator=(const Cat &obj);

    void makeSound(void) const;
};

#endif
