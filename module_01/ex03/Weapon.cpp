#include <Weapon.h>

Weapon::Weapon(std::string type) : type(type) {};

std::string const &Weapon::getType(void) const
{
    return (this->type);
}

void Weapon::setType(std::string type)
{
    this->type = type;
}

// class Weapon {
// public:
// std::string const &getType(void);
// void setType(std::string type);

// private:
// std::string type;

// };