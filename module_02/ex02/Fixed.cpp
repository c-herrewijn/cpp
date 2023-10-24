#include <iostream>
#include <Fixed.h>
#include <limits.h>
#include <cmath>

const int Fixed::_nrFractionalBits = 8;

// constructors / destructors
// -------------------------------
Fixed::Fixed() : _raw(0) {}
Fixed::~Fixed() {};

Fixed::Fixed(const int i)
{
    this->setRawBits(i << this->_nrFractionalBits);
}

Fixed::Fixed(const float f)
{
    int raw = roundf(f * (1 << this->_nrFractionalBits));
    this->setRawBits(raw);
}

Fixed::Fixed(const Fixed &obj)
{
    *this = obj;
}

// operator overloads
// -------------------------------
Fixed &Fixed::operator=(const Fixed &obj)
{
    this->setRawBits(obj.getRawBits());
    return *this;
}

// comparison operators
// -------------------------------
bool Fixed::operator>(const Fixed &obj) const
{
    return (this->getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (this->getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (this->getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (this->getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (this->getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (this->getRawBits() != obj.getRawBits());
}

// arithmetic operators
// -------------------------------
Fixed Fixed::operator+(const Fixed &obj) const
{
    Fixed sum;
    sum.setRawBits(this->getRawBits() + obj.getRawBits());
    return (sum);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    Fixed difference;
    difference.setRawBits(this->getRawBits() - obj.getRawBits());
    return (difference);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    long long int prod_raw = this->getRawBits() * obj.getRawBits();
    Fixed product;
    product.setRawBits(prod_raw >> this->_nrFractionalBits);
    return (product);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    // zero division
    Fixed zero(0);
    if (zero == obj) {
        Fixed inf;
        if (*this >= 0) {
            inf.setRawBits(INT_MAX);
        }
        else {
            inf.setRawBits(INT_MIN);
        }
        return inf;
    }

    // normal case
    float f = (double)this->getRawBits() / (double)obj.getRawBits();
    Fixed division(f);
    return (division);
}

// increment/decrement operators
// -------------------------------
// pre-increment
Fixed &Fixed::operator++()
{
    this->setRawBits(this->getRawBits() + 1);
    return (*this);
}

// post-increment
Fixed Fixed::operator++(int dummy)
{
    (void)dummy;
    Fixed orig(*this);
    this->setRawBits(this->getRawBits() + 1);
    return (orig);
}

// pre-decrement
Fixed &Fixed::operator--()
{
    this->setRawBits(this->getRawBits() - 1);
    return (*this);
}

// post-decrement
Fixed Fixed::operator--(int dummy)
{
    (void)dummy;
    Fixed orig(*this);
    this->setRawBits(this->getRawBits() - 1);
    return (orig);
}

// out stream overload
// -------------------------------
std::ostream &operator<<(std::ostream &out, const Fixed &obj)
{
    out << obj.toFloat();
    return (out);
}

// regular member functions
// -------------------------------
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

// static member functions
// -------------------------------
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
    return (f1 < f2 ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
    return (f1 > f2 ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
    return (f1 < f2 ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
    return (f1 > f2 ? f1 : f2);
}
