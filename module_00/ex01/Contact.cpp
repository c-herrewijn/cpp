#include "Contact.h"
#include <string>

Contact::Contact(void) :
	_first_name(""),
	_last_name(""), 
	_nick_name(""), 
	_phone_number(""), 
	_darkest_secret("")
{
	std::cout << "contact constructor called" << std::endl;
	_nr_instances += 1;
}

Contact::~Contact(void) {
	std::cout << "contact destructor called" << std::endl;
	_nr_instances -= 1;
}

void	Contact::print(void) const {
	std::cout << "first name: " << this->_first_name << std::endl;
}

int		Contact::get_nr_instances(void) {
	return(Contact::_nr_instances);
}

int		Contact::_nr_instances = 0;
