#include <Fixed.h>
#include <iostream>

#include <iostream>
int main(void)
{
    // default tests
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.42f);
    Fixed const d(b);

    a = Fixed(1234.4321f);

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // test with negative numbers
    Fixed const e(-42.42f);
    Fixed const f(e);
    std::cout << "e is " << e << std::endl;
    std::cout << "f is " << f << std::endl;

    // Min Max tests
    Fixed const f_small_pos(0.00390625f);
    Fixed const f_small_neg(-0.00390625f);
    std::cout << "f_small_pos is " << f_small_pos << std::endl;
    std::cout << "f_small_neg is " << f_small_neg << std::endl;

    Fixed const f_max_pos((1<<23)-1);
    Fixed const f_max_neg((-1)<<23);
    std::cout << "f_max_pos is " << f_max_pos << std::endl;
    std::cout << "f_max_neg " << f_max_neg << std::endl;

    return 0;
}
