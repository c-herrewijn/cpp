#include <Contact.h>

#include <iomanip>
#include <iostream>
#include <string>

void Contact::set_contact_attributes(size_t index, std::string first_name,
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

void Contact::set_index(size_t index)
{
    this->_index = index;
}

void Contact::print_contact_line(size_t col_width) const
{
    std::cout << std::setw(col_width) << this->_index << "|"
              << std::setw(col_width) << _crop_string(this->_first_name, col_width) << "|"
              << std::setw(col_width) << _crop_string(this->_last_name, col_width) << "|"
              << std::setw(col_width) << _crop_string(this->_nickname, col_width)
              << std::endl;
}

void Contact::print_contact_info(void) const
{
    std::cout << "first name:     " << this->_first_name << std::endl
              << "last name:      " << this->_last_name << std::endl
              << "nickname:       " << this->_nickname << std::endl
              << "phone number:   " << this->_phone_number << std::endl
              << "darkest secret: " << this->_darkest_secret << std::endl;
}

std::string Contact::_crop_string(std::string str, size_t crop_width) const
{
    if (str.length() > crop_width) {
        str.resize(crop_width, ' ');
        str[crop_width - 1] = '.';
    }
    return (str);
}
