#ifndef AMATERIA_H
# define AMATERIA_H

#include "ICharacter.h"
#include <string>

class  AMateria {
public:
    virtual ~AMateria();
    AMateria &operator=(const AMateria &obj);

    std::string const &getType() const;  //Returns the materia type
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);

protected:
    AMateria();
    AMateria(std::string const &type);
    AMateria(const AMateria &obj);

private:
    std::string const type;
};

#endif
