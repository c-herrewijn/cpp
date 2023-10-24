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
    bool operator>(const Fixed &obj);
    bool operator<(const Fixed &obj);
    bool operator>=(const Fixed &obj);
    bool operator<=(const Fixed &obj);
    bool operator==(const Fixed &obj);
    bool operator!=(const Fixed &obj);
    Fixed operator+(const Fixed &obj);
    Fixed operator-(const Fixed &obj);
    Fixed operator*(const Fixed &obj);
    Fixed operator/(const Fixed &obj);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

private:
    int _raw;
    static const int _nrFractionalBits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &obj);

#endif
