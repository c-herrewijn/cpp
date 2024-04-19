#include <iostream>
#include <stdexcept>

#include "Span.hpp"

void testAdd(Span &sp, int n)
{
    try {
        sp.addNumber(n);
        std::cout << "number added: " << n << std::endl;
    }
    catch (std::range_error &e) {
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    Span sp = Span(3);

    testAdd(sp, 12);
    testAdd(sp, 15);
    testAdd(sp, 12);
    testAdd(sp, 15);
}
