#include <iostream>
#include <iterator>
#include <stack>
#include <list>

#include "MutantStack.hpp"

#define ANSI_RED   "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_CYAN  "\x1b[36m"
#define ANSI_RESET "\x1b[0m"

void testMutantStackBasic()
{
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

void testConstructors()
{
    std::cout << ANSI_CYAN << "\nConstructor tests" << ANSI_RESET << std::endl;
    MutantStack<int> s1;
    s1.push(2);
    s1.push(3);

    std::cout << "deep copy via copy constructor" << std::endl;
    MutantStack<int> s2(s1);
    std::cout << "  s1.size(): " << s1.size() << "; s1.top(): " << s1.top() << std::endl;
    std::cout << "  s2.size(): " << s2.size() << "; s2.top(): " << s2.top() << std::endl;
    std::cout << "  adjusting s1..." << std::endl;
    s1.push(5);
    std::cout << "  s1.size(): " << s1.size() << "; s1.top(): " << s1.top() << std::endl;
    std::cout << "  s2.size(): " << s2.size() << "; s2.top(): " << s2.top() << std::endl;

    MutantStack<int> s3 = s1;
    std::cout << "deep copy via copy assignment operator" << std::endl;
    std::cout << "  s1.size(): " << s1.size() << "; s1.top(): " << s1.top() << std::endl;
    std::cout << "  s3.size(): " << s3.size() << "; s3.top(): " << s3.top() << std::endl;
    std::cout << "  adjusting s1..." << std::endl;
    s1.push(7);
    std::cout << "  s1.size(): " << s1.size() << "; s1.top(): " << s1.top() << std::endl;
    std::cout << "  s3.size(): " << s3.size() << "; s3.top(): " << s3.top() << std::endl;
}

void testIterator()
{
    std::cout << ANSI_CYAN << "\nIterator tests" << ANSI_RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(2);
    mstack.push(3);
    mstack.push(5);
    mstack.push(7);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "iterate over MutantStack and print" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        it++;
    }

    std::cout << "compare with other container (list)" << std::endl;
    std::list<int> mlist;
    mlist.push_front(2);
    mlist.push_front(3);
    mlist.push_front(5);
    mlist.push_front(7);

    std::list<int>::iterator v_it = mlist.begin();
    std::list<int>::iterator v_ite = mlist.end();
    std::cout << "iterate over list and print" << std::endl;
    while (v_it != v_ite) {
        std::cout << *v_it << std::endl;
        v_it++;
    }
}

void testConversionOperator()
{
    std::cout << ANSI_CYAN << "\nTest conversion to regular stack" << ANSI_RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(2);
    mstack.push(3);
    mstack.push(5);
    mstack.push(7);

    std::stack<int> s(mstack);
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
}

void testIteratorIncrements()
{
    std::cout << ANSI_CYAN << "\nIterator Increments and Decremets" << ANSI_RESET << std::endl;
    MutantStack<int> mstack;
    mstack.push(2);
    mstack.push(3);
    mstack.push(5);
    mstack.push(7);
    MutantStack<int>::iterator it = mstack.begin();

    std::cout << "test ++ and -- operators" << std::endl;
    std::cout << *it << std::endl;
    std::cout << *(++it) << std::endl;
    std::cout << *(it++) << std::endl;
    std::cout << *it << std::endl;
    std::cout << *(--it) << std::endl;
    std::cout << *(it--) << std::endl;
    std::cout << *it << std::endl;

    std::cout << "test equality operators" << std::endl;
    MutantStack<int>::iterator it_a = mstack.begin();
    MutantStack<int>::iterator it_b = mstack.begin();
    MutantStack<int>::iterator it_c = mstack.begin();
    it_c++;

    std::cout << "it_a == it_b, (true)  : " << (it_a == it_b) << std::endl;
    std::cout << "it_a == it_c, (false) : " << (it_a == it_c) << std::endl;
    std::cout << "it_a != it_b, (false) : " << (it_a != it_b) << std::endl;
    std::cout << "it_a != it_c, (true)  : " << (it_a != it_c) << std::endl;
}

void testStrings() {
    std::cout << ANSI_CYAN << "\nTest with strings" << ANSI_RESET << std::endl;
    MutantStack<std::string> mstack;
    mstack.push("aa");
    mstack.push("bb");
    mstack.push("cc");
    mstack.push("dd");
    for (MutantStack<std::string>::iterator it=mstack.begin(); it!=mstack.end(); it++) {
        std::cout << *it << std::endl;
    }
}

int main()
{
    testMutantStackBasic();
    testConstructors();
    testIterator();
    testIteratorIncrements();
    testConversionOperator();
    testStrings();
}
