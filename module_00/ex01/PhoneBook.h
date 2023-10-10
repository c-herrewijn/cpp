#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "Contact.h"

class PhoneBook {
public:
    PhoneBook(void);
    ~PhoneBook(void);

    void add(std::string first_name, std::string last_name,
             std::string nick_name, std::string phone_number,
             std::string darkest_secret);
    void print_contact_list(void) const;
    void print_contact_at_index(unsigned int index) const;
    unsigned int get_nr_contacts(void) const;

private:
    unsigned int _nr_contacts = 0;
    Contact _contact_list[8];

    void _reset_indices(void);
};

#endif
