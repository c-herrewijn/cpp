#include <iostream>
#include "Contact.h"

Contact::Contact(void)
{
    std::cout << "contact constructor called" << std::endl;
}

Contact::~Contact(void)
{
    std::cout << "contact destructor called" << std::endl;
}

