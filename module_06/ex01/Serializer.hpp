#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <cstdint>
#include "Data.hpp"

class Serializer {
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

private:
    Serializer();
    ~Serializer();
    Serializer(const Serializer &obj);
    Serializer &operator=(const Serializer &obj);
};

#endif
