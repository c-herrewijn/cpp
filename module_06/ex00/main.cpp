#include "ScalarConverter.hpp"
#include <iostream>

#include <math.h> // debug, for sqrt only
#include <limits>

int main()
{
    ScalarConverter::convert("dummy");

    char c = 'a';
    int i = 42;
    float f = 42.0f;
    double d = 42.0;
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    std::cout << "double size: " << sizeof(double)  << std::endl;

    float specialFloat;

    specialFloat = -1.0 / 0.0;
    std::cout << "inf: " << specialFloat << std::endl;
    specialFloat = std::numeric_limits<float>::infinity() * -1;
    std::cout << "special inf: " << specialFloat << std::endl;
    specialFloat = sqrt(-1);
    std::cout << "nan: " << specialFloat << std::endl;

    specialFloat = std::numeric_limits<float>::quiet_NaN();
    std::cout << "quiet_NaN: " << specialFloat << std::endl;

    double dmax = std::numeric_limits<double>::max();
    std::cout << "double max: " << dmax << std::endl;

}
