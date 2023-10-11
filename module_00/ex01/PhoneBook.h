#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "Contact.h"

class PhoneBook {
public:
    PhoneBook(void);
    ~PhoneBook(void);

    bool query_for_new_contact(void);
    void print_contact_list(void) const;
    void print_contact_at_index(unsigned int index) const;
    unsigned int get_nr_contacts(void) const;

private:
    unsigned int _nr_contacts = 0;
    Contact _contact_list[8];

    bool _query_for_contact_attribute(std::string &attribute,
                                      std::string query_str) const;
    void _add_contact(std::string first_name, std::string last_name,
                      std::string nick_name, std::string phone_number,
                      std::string darkest_secret);
    void _reset_indices(void); // todo, check if can be const
};

#endif
