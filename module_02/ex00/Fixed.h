#ifndef FIXED_H
#define FIXED_H

class Fixed {
public:
    Fixed();
    Fixed(const Fixed &obj);
    ~Fixed();
    Fixed &operator=(const Fixed &obj);

    int getRawBits(void) const;
    void setRawBits(int const raw);

private:
    int _raw;
    static const int _nrFractionalBits;
};

#endif
