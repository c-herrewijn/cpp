#include <PhoneBook.h>

#include <iomanip>
#include <iostream>
#include <string>

bool PhoneBook::user_add_contact(void)
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
    std::string darkest_secret;

    std::cout << "Enter new contact details" << std::endl;
    if (this->_query_for_input(first_name, "first name: ")
            && this->_query_for_input(last_name, "last name: ")
            && this->_query_for_input(nickname, "nickname: ")
            && this->_query_for_input(phone_number, "phone number: ")
            && this->_query_for_input(darkest_secret, "darkest secret: ")
       ) {
        this->_add_contact(first_name, last_name, nickname, phone_number,
                           darkest_secret);
        return (true);
    }
    else {
        return (false);
    }
}

bool PhoneBook::search_contact(void)
{
    if (this->_get_nr_contacts() == 0) {
        std::cout << "The phonebook is empty" << std::endl;
    }
    else {
        this->_print_contact_list();
        std::string input_str;
        int index = -1;
        while (index < 0) {
            if (!this->_query_for_input(input_str, "Enter contact index: ")) {
                return (false);
            }
            index = this->_input_to_index(input_str);
            if (index < 0) {
                std::cout << "Invalid index!" << std::endl;
            }
            else {
                _print_contact_at_index((unsigned int)index);
            }
        }
    }
    return (true);
}

void PhoneBook::_add_contact(std::string first_name, std::string last_name,
                             std::string nickname, std::string phone_number,
                             std::string darkest_secret)
{
    unsigned int index = _get_nr_contacts();

    if (index < 8) {
        this->_contact_list[index].fill_contact(
            index, first_name, last_name, nickname, phone_number, darkest_secret);
        _nr_contacts += 1;
    }
    else {
        for (int i = 0; i < 7; i++) {
            this->_contact_list[i] = this->_contact_list[i + 1];
        }
        this->_contact_list[7].fill_contact(
            index, first_name, last_name, nickname, phone_number, darkest_secret);
        this->_reset_indices();
    }
}

void PhoneBook::_reset_indices(void)
{
    for (unsigned int i = 0; i < this->_nr_contacts; i++) {
        this->_contact_list[i].update_index(i);
    }
}

bool PhoneBook::_query_for_input(std::string &attribute,
                                 std::string query_str) const
{
    std::string input;
    while (true) {
        std::cout << query_str;
        if (!std::getline(std::cin, input) || std::cin.eof()) {
            return false;
        }
        if (!input.empty()) {
            attribute = input;
            break;
        }
    }
    return (true);
}

unsigned int PhoneBook::_get_nr_contacts(void) const
{
    return (PhoneBook::_nr_contacts);
}

void PhoneBook::_print_contact_list(void) const
{
    std::cout << std::setw(this->_col_width) << "index" << "|"
              << std::setw(this->_col_width) << "first name" << "|"
              << std::setw(this->_col_width) << "last name" << "|"
              << std::setw(this->_col_width) << "nickname" << std::endl;
    for (unsigned int i = 0; i < _get_nr_contacts(); i++) {
        this->_contact_list[i].print_contact_line(this->_col_width);
    }
}

int PhoneBook::_input_to_index(std::string input) const
{
    for (char c : input) {
        if (!isdigit(c)) {
            return (-1);
        }
    }
    int index = std::stoi(input);
    if (index < 0 || index + 1 > (int)this->_get_nr_contacts()) {
        return (-1);
    }
    return (index);
}

void PhoneBook::_print_contact_at_index(unsigned int index) const
{
    if (index >= _nr_contacts) {
        std::cout << "Error: index out of range, no contact at index: " << index <<
                  std::endl;
    }
    else {
        this->_contact_list[index].print_contact_info();
    }
}
