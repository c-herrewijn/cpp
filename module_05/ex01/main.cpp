#include "Bureaucrat.h"
#include "Form.h"
#include <iostream>

int main()
{
    Bureaucrat b1("King", 1);
    Bureaucrat b2("Baron", 10);

    // todo: invalid form creation
    std::cout << "Testing invalid form creation..." << std::endl;
    std::cout << "todo" << std::endl;
    std::cout << "------------" << std::endl;

    std::cout << "Testing valid form creation.." << std::endl;
    Form f1("Royal Decree", 1, 1);
    Form f2("Noble Decree", 10, 10);
    Form f3("Common Decree", 100, 100);
    std::cout << "done" << std::endl;
    std::cout << "------------" << std::endl;

    std::cout << "Testing invalid form signing.." << std::endl;
    b2.signForm(f1);
    std::cout << "------------" << std::endl;

    std::cout << "Testing valid form signing.." << std::endl;
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
    b1.signForm(f1);
    b2.signForm(f2);
    b2.signForm(f3);
    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;
}
