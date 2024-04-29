#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &obj)
{
    *this = obj;
}

RPN::~RPN() {}

RPN &RPN::operator=(const RPN &obj)
{
    // todo -> copy attributes
    this->stack = obj.stack;
    return *this;
}
