#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include "Contact.h"

class PhoneBook {
public:
    PhoneBook(void);
    ~PhoneBook(void);
    bool user_add(void);
    bool user_search(void);

private:
    unsigned int _nr_contacts = 0;
    Contact _contact_list[8];

    void _add_contact(std::string first_name, std::string last_name,
                      std::string nick_name, std::string phone_number,
                      std::string darkest_secret);
    void _reset_indices(void);
    bool _query_for_input(std::string &attribute, std::string query_str) const;
    unsigned int _get_nr_contacts(void) const;
    void _print_contact_list(void) const;
    int _input_to_index(std::string input) const;
    void _print_contact_at_index(unsigned int index) const;
};

#endif
