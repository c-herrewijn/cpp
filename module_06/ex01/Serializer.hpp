#include <cstdint>
#include <string>

struct Data {
    std::string str;
    unsigned char chars[12];
    bool b;
};

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
