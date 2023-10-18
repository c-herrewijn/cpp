#include <Harl.h>

int main()
{
    Harl myHarl;

    myHarl.complain("debug");
    myHarl.complain("info");
    myHarl.complain("warning");
    myHarl.complain("error");
    myHarl.complain("non-valid");

    myHarl.complain("debug");
    myHarl.complain("info");
    myHarl.complain("warning");
    myHarl.complain("error");
    myHarl.complain("non-valid");
}