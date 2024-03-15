#include "Identify.hpp"
#include <exception>
#include <stdexcept>
#include <iostream>

int main()
{
    try {
        Base *b = generate();
        identify(b);
        identify(*b);
        delete b;
    }
    catch (std::logic_error &e) {
        std::cout << e.what() << std::endl;
    }
}
