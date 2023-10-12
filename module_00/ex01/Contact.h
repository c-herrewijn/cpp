#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
public:
    void set_contact_attributes(size_t index, std::string first_name,
                                std::string last_name, std::string nickname,
                                std::string phone_number, std::string darkest_secret);
    void set_index(size_t index);
    void print_contact_line(size_t col_width) const;
    void print_contact_info(void) const;

private:
    size_t _index;
    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _phone_number;
    std::string _darkest_secret;

    std::string _crop_string(std::string str, size_t crop_width) const;
};

#endif
