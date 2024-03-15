#include "Identify.hpp"
#include <random>
#include <chrono>
#include <iostream>
#include <stdexcept>

Base *generate(void)
{
    // random nr: 0, 1, or 2
    unsigned int seed = static_cast<unsigned int>
                        (std::chrono::steady_clock::now().time_since_epoch().count());
    srand(seed);
    int randnr = (std::rand() % 3);

    Base *basePtr;
    switch (randnr) {
    case 0:
        basePtr = new A();
        break;
    case 1:
        basePtr = new B();
        break;
    case 2:
        basePtr = new C();
        break;
    default:
        throw std::logic_error("random switch case could not be determined");
    }
    return basePtr;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != nullptr) {
        std::cout << "Identified object via ptr type = A" << std::endl;
    }
    if (dynamic_cast<B *>(p) != nullptr) {
        std::cout << "Identified object via ptr type = B" << std::endl;
    }
    if (dynamic_cast<C *>(p) != nullptr) {
        std::cout << "Identified object via ptr type = C" << std::endl;
    }
}

void identify(Base &p)
{
    try {
        (void)dynamic_cast<A &>(p);
        std::cout << "Identified object via ref type = A" << std::endl;
    }
    catch (std::bad_cast) {}

    try {
        (void)dynamic_cast<B &>(p);
        std::cout << "Identified object via ref type = B" << std::endl;
    }
    catch (std::bad_cast) {}

    try {
        (void)dynamic_cast<C &>(p);
        std::cout << "Identified object via ref type = C" << std::endl;
    }
    catch (std::bad_cast) {}
}
