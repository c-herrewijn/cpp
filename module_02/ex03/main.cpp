#include <iostream>
#include <Point.h>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    // --------------------------------
    // TEST 1
    // define triangle
    std::cout << "Test Case 1: " << std::endl;
    Point const a1(-1.0f, 1.0f);
    Point const b1(3.0f, 4.0f);
    Point const c1(4.0f, -1.0f);

    // points outside
    std::cout << "res: " << bsp(a1, b1, c1, Point(1.0f, 2.8f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a1, b1, c1, Point(0.0f, 0.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a1, b1, c1, Point(0.0f, 2.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a1, b1, c1, Point(0.0f, 3.9f)) << "; 0 exp" << std::endl;

    // points inside
    std::cout << "res: " << bsp(a1, b1, c1, Point(2.0f, 2.0f)) << "; 1 exp" << std::endl;
    std::cout << "res: " << bsp(a1, b1, c1, Point(0.0f, 1.0f)) << "; 1 exp" << std::endl;
    std::cout << "res: " << bsp(a1, b1, c1, Point(3.0f, 0.0f)) << "; 1 exp" << std::endl;
    std::cout << "res: " << bsp(a1, b1, c1, Point(-0.5f, 1.0f)) << "; 1 exp" << std::endl;

    // --------------------------------
    // TEST 2
    // define triangle
    std::cout << "Test Case 2: " << std::endl;
    Point const a2(0.0f, 0.0f);
    Point const b2(6.0f, 0.0f);
    Point const c2(0.0f, 3.0f);

    // points outside
    std::cout << "res: " << bsp(a2, b2, c2, Point(-1.0f, 0.8f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(0.5f, -1.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(3.0f, 2.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(2.0f, 5.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(5.0f, 5.0f)) << "; 0 exp" << std::endl;

    // edge cases (defined to be outside):
    std::cout << "res: " << bsp(a2, b2, c2, Point(0.0f, 0.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(0.0f, 1.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(0.0f, 3.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(2.0f, 2.0f)) << "; 0 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(6.0f, 0.0f)) << "; 0 exp" << std::endl;

    // points inside
    std::cout << "res: " << bsp(a2, b2, c2, Point(0.5f, 0.5f)) << "; 1 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(0.5f, 2.5f)) << "; 1 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(2.0f, 1.5f)) << "; 1 exp" << std::endl;
    std::cout << "res: " << bsp(a2, b2, c2, Point(5.1f, 0.1f)) << "; 1 exp" << std::endl;
    return (0);
}