#include <Fixed.h>
#include <iostream>

#include <iostream>
int main(void)
{
    Fixed m(2.3f);

    Fixed aa(1.3f);
    Fixed bb(2.3f);
    Fixed cc(3.3f);

    // testing comparison operators
    std::cout << "m > aa: " << (m > aa) << "; 1 is expected" << std::endl;
    std::cout << "m > bb: " << (m > bb) << "; 0 is expected" << std::endl;
    std::cout << "m > cc: " << (m > cc) << "; 0 is expected" << std::endl;

    std::cout << "m < aa: " << (m < aa) << "; 0 is expected" << std::endl;
    std::cout << "m < bb: " << (m < bb) << "; 0 is expected" << std::endl;
    std::cout << "m < cc: " << (m < cc) << "; 1 is expected" << std::endl;

    std::cout << "m >= aa: " << (m >= aa) << "; 1 is expected" << std::endl;
    std::cout << "m >= bb: " << (m >= bb) << "; 1 is expected" << std::endl;
    std::cout << "m >= cc: " << (m >= cc) << "; 0 is expected" << std::endl;

    std::cout << "m <= aa: " << (m <= aa) << "; 0 is expected" << std::endl;
    std::cout << "m <= bb: " << (m <= bb) << "; 1 is expected" << std::endl;
    std::cout << "m <= cc: " << (m <= cc) << "; 1 is expected" << std::endl;

    std::cout << "m == aa: " << (m == aa) << "; 0 is expected" << std::endl;
    std::cout << "m == bb: " << (m == bb) << "; 1 is expected" << std::endl;
    std::cout << "m == cc: " << (m == cc) << "; 0 is expected" << std::endl;

    std::cout << "m != aa: " << (m != aa) << "; 1 is expected" << std::endl;
    std::cout << "m != bb: " << (m != bb) << "; 0 is expected" << std::endl;
    std::cout << "m != cc: " << (m != cc) << "; 1 is expected" << std::endl;

    // testing arithmetic operators
    Fixed ar1(-4.4f);
    std::cout << "m + ar1: " << (m + ar1) << "; -2.1 is expected" << std::endl;
    std::cout << "m - ar1: " << (m - ar1) << "; 6.7 is expected" << std::endl;

    std::cout << "m * ar1: " << (m * ar1) << "; -10.12 is expected" << std::endl;
    std::cout << "10.25 * 1.25: " << (Fixed(10.25f) * Fixed(1.25f)) << "; 12.8125 is expected" << std::endl;

    std::cout << "m / ar1: " << (m / ar1) << "; -0.5227 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(10) / Fixed(3)) << "; 3.333 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(7) / Fixed(0.5f)) << "; 14 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(5) / Fixed(0)) << "; (2^23)-1 = 8388607, is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(7000000) / Fixed(2)) << "; 3500000 is expected" << std::endl;
    std::cout << "m / ar1: " << (Fixed(70000) / Fixed(2)) << "; 35000 is expected" << std::endl;

    // testing increment / decrement operators
    Fixed dd;
    std::cout << "dd: " << (dd) << "; 0 is expected" << std::endl;
    std::cout << "dd: " << (dd++) << "; 0 is expected" << std::endl;
    std::cout << "dd: " << (dd++) << "; 0.00390625 is expected" << std::endl;
    std::cout << "dd: " << (dd) << "; 0.0078125 is expected" << std::endl;
    std::cout << "dd: " << (++dd) << "; 0.01171875 is expected" << std::endl;
    std::cout << "dd: " << (++dd) << "; 0.015625 is expected" << std::endl;
    std::cout << "dd: " << (dd) << "; 0.015625 is expected" << std::endl;

    std::cout << "dd: " << (dd--) << "; 0.015625 is expected" << std::endl;
    std::cout << "dd: " << (dd--) << "; 0.01171875 is expected" << std::endl;
    std::cout << "dd: " << (dd) << "; 0.0078125 is expected" << std::endl;
    std::cout << "dd: " << (--dd) << "; 0.00390625 is expected" << std::endl;
    std::cout << "dd: " << (--dd) << "; 0 is expected" << std::endl;
    std::cout << "dd: " << (dd) << "; 0 is expected" << std::endl;

    // testing min/max
    Fixed ee(10.25f);
    Fixed ff(11);
    std::cout << "min: " << Fixed::min(ee, ff) << "; 10.25 is expected" << std::endl;

    Fixed gg(10);
    const Fixed hh(-11);
    std::cout << "min: " << Fixed::min(gg, hh) << "; -11 is expected" << std::endl;

    Fixed ii(10.25f);
    Fixed jj(11);
    std::cout << "min: " << Fixed::min(ii, jj) << "; 10.25 is expected" << std::endl;

    Fixed kk(10);
    const Fixed mm(-11);
    std::cout << "min: " << Fixed::min(kk, mm) << "; -11 is expected" << std::endl;

    // test cases from subject
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    return 0;
}
