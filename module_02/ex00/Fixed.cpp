#include <iostream>
#include <Fixed.h>

const int Fixed::_nrFractionalBits = 8;

Fixed::Fixed() : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->_raw = obj.getRawBits();
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->_raw = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{

    std::cout << "getRawBits member function called" << std::endl;
    return (this->_raw);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_raw = raw;
}
