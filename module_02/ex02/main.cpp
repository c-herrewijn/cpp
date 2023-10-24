#include <Fixed.h>
#include <iostream>

#include <iostream>
int main(void)
{
    Fixed m(2.3f);

    Fixed a(1.3f);
    Fixed b(2.3f);
    Fixed c(3.3f);

    // testing comparison operators
    std::cout << "m > a: " << (m > a) << "; 1 is expected" << std::endl;
    std::cout << "m > b: " << (m > b) << "; 0 is expected" << std::endl;
    std::cout << "m > c: " << (m > c) << "; 0 is expected" << std::endl;

    std::cout << "m < a: " << (m < a) << "; 0 is expected" << std::endl;
    std::cout << "m < b: " << (m < b) << "; 0 is expected" << std::endl;
    std::cout << "m < c: " << (m < c) << "; 1 is expected" << std::endl;

    std::cout << "m >= a: " << (m >= a) << "; 1 is expected" << std::endl;
    std::cout << "m >= b: " << (m >= b) << "; 1 is expected" << std::endl;
    std::cout << "m >= c: " << (m >= c) << "; 0 is expected" << std::endl;

    std::cout << "m <= a: " << (m <= a) << "; 0 is expected" << std::endl;
    std::cout << "m <= b: " << (m <= b) << "; 1 is expected" << std::endl;
    std::cout << "m <= c: " << (m <= c) << "; 1 is expected" << std::endl;

    std::cout << "m == a: " << (m == a) << "; 0 is expected" << std::endl;
    std::cout << "m == b: " << (m == b) << "; 1 is expected" << std::endl;
    std::cout << "m == c: " << (m == c) << "; 0 is expected" << std::endl;

    std::cout << "m != a: " << (m != a) << "; 1 is expected" << std::endl;
    std::cout << "m != b: " << (m != b) << "; 0 is expected" << std::endl;
    std::cout << "m != c: " << (m != c) << "; 1 is expected" << std::endl;

    // testing arithmetic operators
    Fixed ar1(-4.4f);
    std::cout << "m + ar1: " << (m + ar1) << "; -2.1 is expected" << std::endl;
    std::cout << "m - ar1: " << (m - ar1) << "; 6.7 is expected" << std::endl;

    std::cout << "m * ar1: " << (m * ar1) << "; -10.12 is expected" << std::endl;
    std::cout << "m * ar1: " << (Fixed(10.01f) * Fixed(10.01f)) << "; 100.2001 is expected" << std::endl;
    
    std::cout << "m / ar1: " << (m / ar1) << "; -0.5227 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(10) / Fixed(3)) << "; 3.333 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(7) / Fixed(0.5f)) << "; 14 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(5) / Fixed(0)) << "; (2^23)-1 = 8388607, is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(7000000) / Fixed(2)) << "; 3500000 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(70000) / Fixed(2)) << "; 35000 is expected" << std::endl;

    // test cases from subject
    // Fixed a;
    // Fixed const b(Fixed(5.05f) * Fixed(2));
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}
