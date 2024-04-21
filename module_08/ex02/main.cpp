#include <iostream>

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::cout << mstack.empty() << std::endl;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    std::cout << mstack.size() << std::endl;
    std::cout << mstack.empty() << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    std::cout << *it << std::endl;
    MutantStack<int>::iterator it2 = mstack.end();
    std::cout << *it2 << std::endl;

    return 0;
}
