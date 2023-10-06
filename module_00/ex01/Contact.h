#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

class Contact {
private:
    std::string _first_name;
    std::string _last_name;
    std::string _nick_name;
    std::string _phone_number;
    std::string _darkest_secret;
    static int _nr_instances;

public:
    Contact(void);
    Contact(std::string first_name, std::string last_name, std::string nick_name,
            std::string phone_number, std::string darkest_secret);
    ~Contact(void);
    static int get_nr_instances(void);
    void print(void) const;
};

#endif
