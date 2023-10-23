#include <iostream>
#include <Fixed.h>
#include <cmath>

const int Fixed::_nrFractionalBits = 8;

Fixed::Fixed() : _raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i)
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(i << this->_nrFractionalBits);
}

Fixed::Fixed(const float f)
{
    std::cout << "Float constructor called" << std::endl;
    int raw = round((double)f * (1 << this->_nrFractionalBits));
    setRawBits(raw);
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
};

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(obj.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    return (this->_raw);
}

void Fixed::setRawBits(int const raw)
{
    this->_raw = raw;
}

float Fixed::toFloat(void) const
{
    float f = (double)this->getRawBits() / (double)(1 << this->_nrFractionalBits);
    return (f);
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->_nrFractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return (out);
}