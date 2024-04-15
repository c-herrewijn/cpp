#ifndef ARRAY_H
# define ARRAY_H

template <class T>
class Array {
public:
    Array<T>();
    Array<T>(unsigned int n);
    ~Array();
    Array<T>(Array<T> &object);
    Array<T> &operator=(Array<T> const &object);
    Array<T> &operator[](int index);
    unsigned int size(void) const;

    T *_data;
    unsigned int _size;
};

#include "Array.tpp"

#endif
