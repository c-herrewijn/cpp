#include <cstdint>

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &obj)
{
    this->_stack = obj._stack;
    return *this;
}

void RPN::addNumberToStack(int32_t n)
{
    this->_stack.emplace(n);
}

bool RPN::executeOperator(char c)
{
    if (this->_stack.size() < 2) {
        return false;
    }
    if (c == '+' || c == '-' || c == '/' || c == '*') {
        int32_t i1 = this->_stack.top();
        this->_stack.pop();
        int32_t i2 = this->_stack.top();
        this->_stack.pop();
        int64_t res;
        switch (c) {
        case '+' :
            res = i2 + i1;
            break;
        case '-' :
            res = i2 - i1;
            break;
        case '*' :
            res = i2 * i1;
            break;
        case '/' :
            res = i2 / i1;
            break;
        }
        if (res > INT32_MAX) {
            return false;
        }
        else {
            this->_stack.emplace(static_cast<int32_t>(res));
        }
    }
    else {
        return false;
    }
    return true;
}

bool RPN::verifyResult()
{
    return (this->_stack.size() == 1);
}

int32_t RPN::getResult()
{
    return this->_stack.top();
}
