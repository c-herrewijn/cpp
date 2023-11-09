#ifndef AMATERIA_H
# define AMATERIA_H

#include "ICharacter.h"
#include <string>

class ICharacter; // foreward declaration, to prevent circular includes

class AMateria {
public:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &obj);
    virtual ~AMateria();
    AMateria &operator=(const AMateria &obj);

    std::string const &getType() const;  //Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

protected:
    std::string const type;
};

#endif
