#include <Contact.h>

#include <iomanip>
#include <iostream>
#include <string>

Contact::Contact(void) :
    _index(0),
    _first_name(""),
    _last_name(""),
    _nick_name(""),
    _phone_number(""),
    _darkest_secret("") {}

Contact::~Contact(void) {}

void Contact::print_contact_line(void) const
{
    std::cout << std::setw(10) << this->_index << "|"
              << std::setw(10) << _crop_string(this->_first_name) << "|"
              << std::setw(10) << _crop_string(this->_last_name) << "|"
              << std::setw(10) << _crop_string(this->_nick_name) << std::endl;
}

void Contact::print_contact_info(void) const
{
    std::cout << "first name:     " << this->_first_name << std::endl
              << "last name:      " << this->_last_name << std::endl
              << "nick name:      " << this->_nick_name << std::endl
              << "phone number:   " << this->_phone_number << std::endl
              << "darkest secret: " << this->_darkest_secret << std::endl;
}

void Contact::fill_contact(unsigned int index, std::string first_name,
                           std::string last_name, std::string nick_name,
                           std::string phone_number, std::string darkest_secret)
{
    this->_index = index;
    this->_first_name = first_name;
    this->_last_name = last_name;
    this->_nick_name = nick_name;
    this->_phone_number = phone_number;
    this->_darkest_secret = darkest_secret;
}

void Contact::update_index(unsigned int index)
{
    this->_index = index;
}

std::string Contact::_crop_string(std::string str) const
{
    if (str.length() > 10) {
        str.resize(10, ' ');
        str[9] = '.';
    }
    return (str);
}
