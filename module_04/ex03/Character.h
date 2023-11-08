#ifndef CHARACTER_H
# define CHARACTER_H

#include <string>
#include "ICharacter.h"
#include "AMateria.h"

class  Character : public ICharacter {
public:
    Character();
    Character(std::string name);
    Character(const Character &obj);
    ~Character();
    Character &operator=(const Character &obj);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    static AMateria *floor[100];

private:
    std::string name;
    AMateria *inventory[4];
};

#endif
