#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <Contact.h>
# include <string>

class PhoneBook {
public:
    bool user_add_contact(void);
    bool search_contact(void);

private:
    Contact _contact_list[8];
    size_t _nr_contacts = 0;
    size_t _col_width = 10;

    void _add_contact(std::string first_name, std::string last_name,
                      std::string nickname, std::string phone_number,
                      std::string darkest_secret);
    void _reset_indices(void);
    bool _query_for_input(std::string &attribute, std::string query_str) const;
    size_t _get_nr_contacts(void) const;
    void _print_contact_list(void) const;
    int _input_to_index(std::string input) const;
    void _print_contact_at_index(size_t index) const;
};

#endif
