#include "Form.h"

Form::Form() {}

Form::Form(const Form &obj)
{
    *this = obj;
}

Form::~Form() {}

Form &Form::operator=(const Form &obj)
{
    // this->attr1 = obj.attr1;
    // this->attr2 = obj.attr2;
    (void)obj; // place holder;
    return *this;
}
