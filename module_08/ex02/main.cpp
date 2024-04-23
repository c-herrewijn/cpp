#include <iostream>
#include <stack>

#include "MutantStack.hpp"

#define ANSI_RED   "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_CYAN  "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

void testMutantStackBasic() {
    std::cout << ANSI_CYAN << "Basic tests" << ANSI_RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(2);
    mstack.push(3);
    mstack.push(5);
    mstack.push(7);

    std::cout << "size: " << mstack.size() << std::endl;
    std::cout << "empty() : " << mstack.empty() << std::endl;
    std::cout << "top node: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "top node after pop: " << mstack.top() << std::endl;
    std::cout << "popping remainder..." << std::endl;
    mstack.pop();
    mstack.pop();
    mstack.pop();
    std::cout << "size: " << mstack.size() << std::endl;
    std::cout << "empty() : " << mstack.empty() << std::endl;
}


int main()
{
    testMutantStackBasic();

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "test iteration" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "converted into stack" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    return 0;
}
