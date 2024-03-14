#include "Serializer.hpp"
#include <iostream>
#include <string>

int main()
{
    Data myData;
    myData.str = "hello there!";
    myData.chars[0] = 'a';
    myData.chars[1] = 'b';
    myData.chars[2] = 'c';
    myData.b = true;

    uintptr_t serializedData = Serializer::serialize(&myData);
    Data myData2 = *(Serializer::deserialize(serializedData));

    std::cout << myData2.str << std::endl
              << myData2.chars[0] << myData2.chars[1] << myData2.chars[2] << std::endl
              << myData2.b << std::endl;
}
