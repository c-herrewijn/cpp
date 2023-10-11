#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact {
public:
    Contact(void);
    ~Contact(void);

    void print_contact_line(void) const;
    void print_contact_info(void) const;
    void fill_contact(unsigned int index, std::string first_name,
                      std::string last_name, std::string nick_name,
                      std::string phone_number, std::string darkest_secret);
    void update_index(unsigned int index);

private:
    unsigned int _index;
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    std::string _phone_number;
    std::string _darkest_secret;

    std::string _crop_string(std::string str) const;
};

#endif
