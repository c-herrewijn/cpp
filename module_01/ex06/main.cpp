#include <Harl.h>
#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        std::cout << "Error, the program needs to be called with exactly 1 argument"
                  << std::endl;
        return (1);
    }
    Harl myHarl;
    myHarl.complain(argv[1]);
    return (0);
}
