#include "PhoneBook.h"

PhoneBook::PhoneBook(void) {}
PhoneBook::~PhoneBook(void) {}

void PhoneBook::add(std::string first_name, std::string last_name,
                    std::string nick_name, std::string phone_number,
                    std::string darkest_secret)
{
    unsigned int index = get_nr_contacts();

    if (index < 8) {
        this->_contact_list[index].fill_contact(
            index, first_name, last_name, nick_name, phone_number, darkest_secret);
        _nr_contacts += 1;
    }
    else {
        for (int i = 0; i < 7; i++) {
            this->_contact_list[i] = this->_contact_list[i + 1];
        }
        this->_contact_list[7].fill_contact(
            index, first_name, last_name, nick_name, phone_number, darkest_secret);
        this->_reset_indices();
    }
}

void PhoneBook::print_contact_list(void) const
{
    std::cout << "nr of contacts: " << get_nr_contacts() << std::endl; // debug
    std::cout << std::setw(10) << "index" << "|"
              << std::setw(10) << "first name" << "|"
              << std::setw(10) << "last name" << "|"
              << std::setw(10) << "nick name" << std::endl;
    for (unsigned int i = 0; i < get_nr_contacts(); i++) {
        this->_contact_list[i].print_contact_line();
    }
}

void PhoneBook::print_contact_at_index(unsigned int index) const
{
    if (index >= _nr_contacts) {
        std::cout << "Error: index out of range, no contact at index: " << index <<
                  std::endl;
    }
    else {
        this->_contact_list[index].print_contact_info();
    }
}

unsigned int PhoneBook::get_nr_contacts(void) const
{
    return (PhoneBook::_nr_contacts);
}

void PhoneBook::_reset_indices(void)
{
    for (unsigned int i = 0; i < this->_nr_contacts; i++) {
        this->_contact_list[i].update_index(i);
    }
}
