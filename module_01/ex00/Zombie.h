#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void announce(void);

private:
    std::string name;
};

#endif
