#ifndef CHARACTER_H
# define CHARACTER_H

#include <string>
#include "ICharacter.h"

class  Character : public ICharacter {
public:
    Character();
    Character(std::string name);
    Character(const Character &obj);
    ~Character();
    Character &operator=(const Character &obj);

    std::string const &getName() const;
    // void equip(AMateria* m) = 0;
    // void unequip(int idx) = 0;
    // void use(int idx, ICharacter& target) = 0;

private:
    std::string name;
};

#endif
