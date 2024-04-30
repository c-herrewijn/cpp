#include <cstdint>
#include <sstream>

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

bool RPN::runInput(std::string inputString)
{
    std::istringstream ss(inputString);
    for (std::string tokenString; ss >> tokenString;) {
        if (tokenString.size() != 1) {
            return false;
        }
        char c = tokenString[0];
        if (std::isdigit(c)) {
            this->_stack.emplace(c - '0');
        }
        else if (c == '+' || c == '-' || c == '/' || c == '*') {
            if (this->_executeOperator(c) == false) {
                return false;
            }
        }
        else {
            return false;
        }
    }
    if (this->_stack.size() != 1) {
        return false;
    }
    return true;
}

int32_t RPN::getResult()
{
    return this->_stack.top();
}

bool RPN::_executeOperator(char c)
{
    int32_t i1, i2;
    int64_t res;

    if (this->_stack.size() < 2) {
        return false;
    }
    i1 = this->_stack.top();
    this->_stack.pop();
    i2 = this->_stack.top();
    this->_stack.pop();
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
    default:
        return false;
    }
    if (res > INT32_MAX) {
        return false;
    }
    this->_stack.emplace(static_cast<int32_t>(res));
    return true;
}
