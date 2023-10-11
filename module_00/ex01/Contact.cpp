#include <Contact.h>

#include <iomanip>
#include <iostream>
#include <string>

void Contact::print_contact_line(unsigned int col_width) const
{
    std::cout << std::setw(col_width) << this->_index << "|"
              << std::setw(col_width) << _crop_string(this->_first_name) << "|"
              << std::setw(col_width) << _crop_string(this->_last_name) << "|"
              << std::setw(col_width) << _crop_string(this->_nickname) << std::endl;
}

void Contact::print_contact_info(void) const
{
    std::cout << "first name:     " << this->_first_name << std::endl
              << "last name:      " << this->_last_name << std::endl
              << "nickname:       " << this->_nickname << std::endl
              << "phone number:   " << this->_phone_number << std::endl
              << "darkest secret: " << this->_darkest_secret << std::endl;
}

void Contact::fill_contact(unsigned int index, std::string first_name,
                           std::string last_name, std::string nickname,
                           std::string phone_number, std::string darkest_secret)
{
    this->_index = index;
    this->_first_name = first_name;
    this->_last_name = last_name;
    this->_nickname = nickname;
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
