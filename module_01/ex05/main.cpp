#include <Harl.h>

int main()
{
    Harl myHarl;

    myHarl.complain("DEBUG");
    myHarl.complain("INFO");
    myHarl.complain("WARNING");
    myHarl.complain("ERROR");
    myHarl.complain("non-valid");

    myHarl.complain("DEBUG");
    myHarl.complain("INFO");
    myHarl.complain("WARNING");
    myHarl.complain("ERROR");
    myHarl.complain("non-valid");
}