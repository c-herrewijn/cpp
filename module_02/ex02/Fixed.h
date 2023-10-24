#ifndef FIXED_H
#define FIXED_H
#include <iostream>

class Fixed {
public:
    Fixed();
    Fixed(const int i);
    Fixed(const float f);
    Fixed(const Fixed &obj);
    ~Fixed();

    Fixed &operator=(const Fixed &obj);
    bool operator>(const Fixed &obj) const;
    bool operator<(const Fixed &obj) const;
    bool operator>=(const Fixed &obj) const;
    bool operator<=(const Fixed &obj) const;
    bool operator==(const Fixed &obj) const;
    bool operator!=(const Fixed &obj) const;
    Fixed operator+(const Fixed &obj) const;
    Fixed operator-(const Fixed &obj) const;
    Fixed operator*(const Fixed &obj) const;
    Fixed operator/(const Fixed &obj) const;
    Fixed &operator++();          // pre-increment
    Fixed operator++(int dummy);  // post-increment
    Fixed &operator--();          // pre-decrement
    Fixed operator--(int dummy);  // post-decrement

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed &min(Fixed &f1, Fixed &f2);
    static Fixed &max(Fixed &f1, Fixed &f2);
    static const Fixed &min(const Fixed &f1, const Fixed &f2);
    static const Fixed &max(const Fixed &f1, const Fixed &f2);

private:
    int _raw;
    static const int _nrFractionalBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
