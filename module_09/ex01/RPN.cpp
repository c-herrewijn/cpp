#include <cstdint>
#include <sstream>

#include "RPN.hpp"
#include <iostream>

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

bool RPN::runInput(std::string inputString, std::string &errString)
{
    std::istringstream ss(inputString);
    for (std::string tokenString; ss >> tokenString;) {
        if (tokenString.size() != 1) {
            errString = "invalid input: '" + tokenString + "'; expecting space separated single chars";
            return false;
        }
        char c = tokenString[0];
        if (std::isdigit(c)) {
            this->_stack.emplace(c - '0');
        }
        else if (this->_executeOperator(c, errString) == false) {
            return false;
        }
    }
    if (this->_stack.size() != 1) {
        errString = "invalid result after calculation: '" + std::to_string(this->_stack.size()) + "' numbers remaining on stack; should be: 1";
        return false;
    }
    return true;
}

int32_t RPN::getResult() const
{
    return this->_stack.top();
}

bool RPN::_executeOperator(char c, std::string &errString)
{
    int32_t i1, i2;
    int64_t res;

    if (this->_stack.size() < 2) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            errString = "operator '" + std::string{c} + "' needs 2 operands";
            return false;
        }
    }
    else {
        i1 = this->_stack.top();
        this->_stack.pop();
        i2 = this->_stack.top();
        this->_stack.pop();
    }
    switch (c) {
    case '+' :
        res = i2 + i1;
        break;
    case '-' :
        res = i2 - i1;
        break;
    case '*' :
        res = static_cast<int64_t>(i2) * static_cast<int64_t>(i1);
        break;
    case '/' :
        if (i1 == 0) {
            errString = "zero devision!";
            return false;
        }
        else {
            res = i2 / i1;
        }
        break;
    default:
        errString = "invalid operator: '" + std::string{c} + "'; supported operators are: + - * /";
        return false;
    }
    if (res > INT32_MAX) {
        errString = "result (or in between result) larger then INT32_MAX";
        return false;
    }
    this->_stack.emplace(static_cast<int32_t>(res));
    return true;
}
