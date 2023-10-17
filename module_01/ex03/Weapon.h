#ifndef WEAPON_H
#define WEAPON_H
#include <string>

class Weapon {
public:
    Weapon(std::string type);

    std::string const &getType(void) const;
    void setType(std::string type);

private:
    std::string type;

};

#endif
