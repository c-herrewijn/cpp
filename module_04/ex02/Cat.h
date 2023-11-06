#ifndef CAT_H
# define CAT_H

#include <string>
#include "Animal.h"
#include "Brain.h"

class Cat : public Animal {
public:
    Cat();
    Cat(const Cat &obj);
    ~Cat();
    Cat &operator=(const Cat &obj);

    void makeSound(void) const;
    void brainDump(void) const;
    void updateBrain(size_t index, std::string idea);

private:
    Brain *_brain;
};

#endif
