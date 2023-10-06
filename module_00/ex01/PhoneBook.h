#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include "Contact.h"

class PhoneBook {
public:
    PhoneBook(void);
    ~PhoneBook(void);

    void add(void);

private:
    Contact _contact_list[8];
};

#endif
